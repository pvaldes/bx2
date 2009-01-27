/*
 * who.h -- header info for the WHO, ISON, and USERHOST queues.
 * Copyright 1996 EPIC Software Labs
 */

#ifndef __who_h__
#define __who_h__

void clean_server_queues (int);

/* WHO queue */

/* XXX This should be in who.c */
typedef struct WhoEntryT
{
	int  refnum;
	int  dirty;
	int  piggyback;
	int  undernet_extended;
	char *undernet_extended_args;
	int  dalnet_extended;
	char *dalnet_extended_args;
        int  who_mask;
	char *who_target;
        char *who_name;
        char *who_host;
        char *who_server;
        char *who_nick;
        char *who_real;
	char *who_stuff;
	char *who_end;
        struct WhoEntryT *next;
	void (*line) (int, const char *, const char *, const char **);
	void (*end) (int, const char *, const char *, const char **);

	Timeval	request_time;
	Timeval	dirty_time;
} WhoEntry;

	BUILT_IN_COMMAND(whocmd);
	void 	whobase (int, char *, 
		   void (*)(int, const char *, const char *, const char **), 
		   void (*)(int, const char *, const char *, const char **));
	void 	whoreply (int, const char *, const char *, const char **);
	void 	xwhoreply (int, const char *, const char *, const char **);
	void 	who_end (int, const char *, const char *, const char **);
	int 	fake_who_end (int, const char *, const char *, const char *);



/* ISON queue */

typedef struct IsonEntryT
{
	char *ison_asked;
	char *ison_got;
	struct IsonEntryT *next;
	void (*line) (int, char *, char *);
	char *oncmd;
	char *offcmd;
	char *endcmd;
} IsonEntry;

	BUILT_IN_COMMAND(isoncmd);
	void 	isonbase 	(int refnum, char *args, void (*line) (int, char *, char *));
	void 	ison_returned 	(int, const char *, const char *, const char **);



/* USERHOST queue */
typedef struct UserhostItemT
{
	char *	nick;
	int   	oper;
	int	connected;
	int   	away;
	const char *	user;
	const char *	host;
	const char *	extra;
} UserhostItem;

typedef struct UserhostEntryT
{
        const char *    format;
        char *          userhost_asked;
        char *          text;
	char *		extra;
        struct UserhostEntryT * next;
        void            (*func) (int, UserhostItem *, const char *, const char *); 
} UserhostEntry;

	BUILT_IN_COMMAND(userhostcmd);
	BUILT_IN_COMMAND(useripcmd);
	BUILT_IN_COMMAND(usripcmd);
	void 	userhostbase 		(int refnum, char *arg, const char *subargs,
					void (*line) (int, UserhostItem *, 
						const char *, const char *), int);
	void 	userhost_returned 	(int, const char *, const char *, const char **);
	void 	userhost_cmd_returned 	(int, UserhostItem *, const char *, const char *);

#endif 
