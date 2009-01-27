/*
 * files.h -- header file for files.c
 * Direct file manipulation for irc?  Unheard of!
 *
 * Copyright 1995, 1997 EPIC Software Labs
 * See the COPYRIGHT file for copyright information
 */

#ifndef __files_h__
#define __files_h__

	int	open_file_for_read 	(const char *);
	int	open_file_for_write 	(const char *, const char *);
	int *	open_exec_for_in_out_err(const char *, char * const *);
	int	target_file_write	(const char *, const char *);
	int	file_write 		(int, int, const char *);
	int	file_writeb 		(int, int, char *);
	char *	file_read 		(int);
	char *	file_readb 		(int, int);
	int	file_eof 		(int);
	int	file_close 		(int);
	int	file_valid		(int);
	int	file_rewind		(int);
	int	file_error		(int);
	int	file_seek		(int, off_t, const char *);
	intmax_t file_tell		(int);
	int	file_skip		(int, int);

	char *	dbmctl			(char *);
#endif
