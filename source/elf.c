/*
 * elf.c: code for generalizing loading from just about anywhere
 *
 * Copyright � 2007 EPIC Software Labs.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notices, the above paragraph (the one permitting redistribution),
 *    this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The names of the author(s) may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
/*
 * This code was contributed to EPIC Software Labs by Alexander Grotewohl,
 * used with permission.
 */
#include "irc.h"
#include "ircaux.h"
#include "elf.h"
#include "output.h"

#ifdef HAVE_LIBARCHIVE
static int archive_fopen(struct epic_loadfile *elf, char *filename, const char *ext, int do_error);
static int find_in_archive(struct archive *a, struct archive_entry **entry, const char *str, int do_error);
#endif

struct epic_loadfile * epic_fopen(char *filename, const char *mode, int do_error)
{
    FILE * doh;
    int    ret;

    struct epic_loadfile *elf;

    elf = (struct epic_loadfile *) new_malloc(sizeof(struct epic_loadfile));

    elf->fp = NULL;
#ifdef HAVE_LIBARCHIVE
    elf->a = NULL;
    elf->entry = NULL;
#endif
    elf->eof = 0;

#ifdef HAVE_LIBARCHIVE
    if (stristr(filename, ".zip")!=-1) {
        ret=archive_fopen(elf, filename, ".zip", do_error);
    } else if (stristr(filename, ".tar")!=-1) {
        ret=archive_fopen(elf, filename, ".tar", do_error);
    }
    else
#endif
	ret = 0;

    if (ret==1)
        return elf;

    if (ret!=-1) { /* archive didnt have loadable data */

        /* Its not a compressed file... Try to open it regular-like. */
        if ((doh = fopen(filename, mode))) {
            elf->fp = doh;
            return elf;
        }
        if (do_error)
            yell("Cannot open file %s: %s", filename, strerror(errno));
    }
    new_free(&elf);

    return NULL;
}


#ifdef HAVE_LIBARCHIVE
/*
 * this one takes a filename and an extension we expect is an archive,
 * and attempts to open it up. it returns -1 on error, 0 if it's not
 * an archive, or 1 if the archive was successfully loaded
 */
static int	archive_fopen(struct epic_loadfile *elf, char *filename, const char *ext, int do_error)
{
    int    ret;

    int    pos;
    char * fname;
    char * extra;
    char * safet;

    fname = LOCAL_COPY(filename);
    safet = LOCAL_COPY(filename);

    extra = fname;

    if ((pos=stristr(fname, ext))!=-1) {

        /*
         * Here we make fname actually point to a real
         * file, instead of virtual files/directories
         * inside the archive.. and check if we're
         * supposed to load a file by default..
         */
        extra+=pos;
        while (*extra!='/') {
            if (*extra==0)
                break;
            extra++;
            pos++;
        }
        safet+=pos;
        *extra++ = 0;

        elf->a = archive_read_new();
        if (!archive_read_support_format_all(elf->a)) {

            if ( !(ret = archive_read_open_file(elf->a, fname, 10240)) ) {
                if ( (strstr(safet, "/"))!=NULL ) { /* specific file provided */
                    if (!find_in_archive(elf->a, &elf->entry, extra, do_error))
                        return 0;
                } else {
                    if (!find_in_archive(elf->a, &elf->entry, ".ircrc", do_error)) { /* bootstrap */
                        if (do_error)
                            yell("No .ircrc in the zip file specified");
                        return -1;
                    }
                }
                /*
                 * Our archive should now be open and pointing to the
                 * beginning of the specified file
                 */
                return 1;
            } /* <-- we can fall off the end */
        }
    }
    return 0;
}

static char *	archive_fgets(char *s, int n, struct archive *a)
{
    int ret, bytes_read;
    char *p = s;
    char c;

    bytes_read=0;
    while (bytes_read < n) {
        ret=archive_read_data(a, &c, 1);
        if (ret>0) {
            bytes_read+=ret;
            *p++ = c;
            if (c=='\n')
                break;
            continue;
        }
        return NULL;
    }
    *p='\0';
    return s;
}
#endif

int	epic_fgetc(struct epic_loadfile *elf)
{
    int ret;
    char c;

    if ((elf->fp)!=NULL) {
        return fgetc(elf->fp);
    }
#ifdef HAVE_LIBARCHIVE
    else if ((elf->a)!=NULL) {
        ret=archive_read_data(elf->a, &c, 1);
        if (ret>0) {
            return c;
        } else {
            elf->eof=1;
            return EOF;
        }
    } 
#endif
    else {
        /* other */
        return EOF;
    }
}

char *	epic_fgets(char *s, int n, struct epic_loadfile *elf)
{
    if ((elf->fp)!=NULL) {
        return fgets(s, n, elf->fp);
    }
#ifdef HAVE_LIBARCHIVE
    else if ((elf->a)!=NULL) {
        return archive_fgets(s, n, elf->a);
    } 
#endif
    else {
        return NULL;
    }
}

int	epic_feof(struct epic_loadfile *elf)
{
    if ((elf->fp)!=NULL) {
        return feof(elf->fp);
    }
#ifdef HAVE_LIBARCHIVE
    else if ((elf->a)!=NULL) {
        return elf->eof;
        /* unspecified */
    } 
#endif
    else {
        return 1;
    }
}

int	epic_fclose(struct epic_loadfile *elf)
{
    if ((elf->fp)!=NULL) {
        return fclose(elf->fp);
    }
#ifdef HAVE_LIBARCHIVE
    else if ((elf->a)!=NULL) {
        archive_read_close(elf->a);
        archive_read_finish(elf->a);
        return 0;
    } 
#endif
    else {
        return EOF;
    }
}

off_t	epic_stat(const char *filename, struct stat *buf)
{
#ifdef HAVE_LIBARCHIVE
    struct  archive *a;
    struct  archive_entry *entry = NULL;
#endif
    int     ret;

    char *  zip;
    char *  zipstr;
    char *  sl;
    int     ziploc;
    int     scan = 0;

#ifdef HAVE_LIBARCHIVE
    /*
     * should probably fill the stat structure with
     * as much as possible.. i don't know what might
     * rely on this information..
     */

    zipstr = LOCAL_COPY(filename);
    sl = LOCAL_COPY(filename);
    zip = zipstr;

    if (((ziploc=stristr(zipstr, ".zip"))!=-1) || ((ziploc=stristr(zipstr, ".tar"))!=-1)) {
        zip+=ziploc;
        while (*zip!='/') {
            if (*zip==0)
                break;
            zip++;
            ziploc++;
        }
        sl+=ziploc;
        *zip++ = 0;

        if ( strstr(sl, "/")!=NULL ) scan=1;

        a = archive_read_new();
        archive_read_support_format_all(a);

        if ( !(ret=archive_read_open_file(a, zipstr, 10240)) ) {
            if (scan) {
                if (!(find_in_archive(a, &entry, zip, 0)) ) {
                    return -1;
                } else {
                    /* this is such a hack, but libarchive consistantly */
                    /* crashes on me when i use it's stat routines */
                    buf->st_size=1;
                    buf->st_mode=33188;

                    archive_read_close(a);
                    archive_read_finish(a);
                    return 0;
                }
            }
        }
    }
#endif

    if (!stat(filename, buf)) {
        return 0;
    } else {
        return -1;
    }
}

#ifdef HAVE_LIBARCHIVE
static int	find_in_archive(struct archive *a, struct archive_entry **entry, const char *str, int do_error)
{
    int ret;

    for (;;) {
        ret = archive_read_next_header(a, entry);
        if (ret == ARCHIVE_EOF) {
            archive_read_close(a);
            archive_read_finish(a);
            return 0;
        }
        if (ret != ARCHIVE_OK) {
            if (do_error) {
                yell("%s", archive_error_string(a));
            }
            archive_read_close(a);
            archive_read_finish(a);
            return 0;
        }

        if (strcmp(archive_entry_pathname(*entry), str)==0)
            break;
    }
    return 1;
}
#endif

