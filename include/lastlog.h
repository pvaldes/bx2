/*
 * lastlog.h: header for lastlog.c 
 *
 * Copyright 1990 Michael Sandrof
 * Copyright 1997 EPIC Software Labs
 * See the COPYRIGHT file, or do a HELP IRCII COPYRIGHT 
 */

#ifndef __lastlog_h__
#define __lastlog_h__

#include "levels.h"

/* 
 * Window and Lastlog are mutually referential.  So we cant include
 * window.h here. so to break the loop we forward declare Window here.
 */
struct WindowStru;

extern	Mask	current_window_mask;
extern	Mask *	new_server_lastlog_mask;
extern	Mask *	old_server_lastlog_mask;

	BUILT_IN_COMMAND(lastlog);

	Mask	real_lastlog_mask 		(void);
	Mask	real_notify_mask 		(void);
	void	set_lastlog_mask 		(void *);
	void	set_lastlog_size 		(void *);
	void	set_notify_mask 		(void *);
	void	trim_lastlog			(struct WindowStru *);
	void	set_current_window_mask 	(void *);
	intmax_t add_to_lastlog 	(struct WindowStru *, const char *);
	char *	function_line			(char *);
	char *	function_lastlog		(char *);
	void	set_new_server_lastlog_mask	(void *);
	void	set_old_server_lastlog_mask	(void *);
	void	reconstitute_scrollback		(struct WindowStru *);

	void	move_all_lastlog		(unsigned, unsigned);
	void	move_lastlog_item_by_string	(unsigned, unsigned, Char *);
	void	move_lastlog_item_by_target	(unsigned, unsigned, Char *);
	void	move_lastlog_item_by_level	(unsigned, unsigned, Mask *);
	void	move_lastlog_item_by_regex	(unsigned, unsigned, Char *);

	void    lastlog_swap_winrefs		(unsigned, unsigned);

#endif /* __lastlog_h_ */
