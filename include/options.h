/*
 * What we're doing here is defining a unique string that describes what
 * compile-time options are in use.  The string is then accessible though
 * a special builtin function.  The point is to allow script writers to
 * know what has been enabled/disabled so they don't try to use a
 * feature that in't available.  As such, only #define's that really
 * affect scripting or direct user interaction are included in the
 * string.  Each option is assigned a unique letter, all of which are
 * concatenated together to form a strig that looks like an irc server's
 * version string.  Some of the options are assigned to non-obvious letters
 * since the string has to be case insensitive.
 */
 
/* Letters left: dhjprwy */

const char compile_time_options[] = {
 
#if 1
					'a',
#endif /* WIND_STACK is now the default */

#ifdef NO_BOTS
 					'b',
#endif /* NO_BOTS */
 
#if 1
					'c',
#endif /* COLOR is now the default */

#ifdef EXEC_COMMAND
 					'e',
#endif /* EXEC_COMMAND */
 
#ifdef USE_FLOW_CONTROL
 					'f',
#endif /* USE_FLOW_CONTROL */
 
#if 1
 					'g',
#endif /* INCLUDE_GLOB_FUNCTION is now the default */
 
#ifdef IMPLIED_ON_HOOKS
					'h',
#endif

#ifdef MIRC_BROKEN_DCC_RESUME
					'i',
#endif /* MIRC_BROKEN_DCC_RESUME */

#ifdef HACKED_DCC_WARNING
					'k',
#endif /* HACKED_DCC_WARNING */

#ifdef HAVE_LONG_LONG
#if defined(HAVE_STRTOLL) || defined(HAVE_ATOQ)
					'l',
#endif
#endif

#if 1
					'm',
#endif /* Indicate that we have /SET COLOR instead of /SET CONTROL_C_COLOR */

#if 1
 					'n',
#endif /* LONG NICKNAMES are now the default */

#ifdef WITH_THREADED_STDOUT
					'o',
#endif

#ifdef HAVE_LIBARCHIVE
					'r',
#endif

#ifdef I_DONT_TRUST_MY_USERS
 					't',
#endif /* I_DONT_TRUST_MY_USERS */

#ifdef UNAME_HACK
 					'u',
#endif /* UNAME_HACK */
 
#ifdef HAVE_ICONV
					'v',
#endif

#if 1
 					'x',
#endif /* EXPERIMENTAL_STACK_HACK is now the default */

#if 1
					'z',
#endif /* ALLOW_STOP_IRC is now the default */

					'\0'
};
