/*
 * cset.h: header for cset.c
 */

#ifndef _CSET_H_
#define _CSET_H_

#include "struct.h"
#include "window.h"
/* This ensures we always have the offsetof() macro */
#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

/* the types of IrcVariables (repeated in vars.h) */
#define BOOL_TYPE_VAR 0
#define CHAR_TYPE_VAR 1
#define INT_TYPE_VAR 2
#define STR_TYPE_VAR 3

/* var_settings indexes ... also used in display.c for highlights */
#define OFF 0
#define ON 1
#define TOGGLE 2

enum CSET_TYPES
{
	AINV_CSET,
	ANNOY_KICK_CSET,
	AOP_CSET,
	AUTO_JOIN_ON_INVITE_CSET,
	AUTO_LIMIT_CSET,
	AUTO_REJOIN_CSET,
	BANTIME_CSET,
	BITCH_CSET,
	CHANMODE_CSET,
	CHANNEL_LOG_CSET,
	CHANNEL_LOG_FILE_CSET,
	CHANNEL_LOG_LEVEL_CSET,
	COMPRESS_MODES_CSET,
	CTCP_FLOOD_BAN_CSET,
	DEOPFLOOD_CSET,
	DEOPFLOOD_TIME_CSET,
	DEOP_ON_DEOPFLOOD_CSET,
	DEOP_ON_KICKFLOOD_CSET,
	HACKING_CSET,
	JOINFLOOD_CSET,
	JOINFLOOD_TIME_CSET,
	KICKFLOOD_CSET,
	KICKFLOOD_TIME_CSET,
	KICK_IF_BANNED_CSET,
	KICK_ON_DEOPFLOOD_CSET,
	KICK_ON_JOINFLOOD_CSET,
	KICK_ON_KICKFLOOD_CSET,
	KICK_ON_NICKFLOOD_CSET,
	KICK_ON_PUBFLOOD_CSET,
	KICK_OPS_CSET,
	LAMEIDENT_CSET,
	LAMELIST_CSET,
	NICKFLOOD_CSET,
	NICKFLOOD_TIME_CSET,
	PUBFLOOD_CSET,
	PUBFLOOD_IGNORE_TIME_CSET,
	PUBFLOOD_TIME_CSET,
	SHITLIST_CSET,
	USERLIST_CSET,
	NUMBER_OF_CSETS
};

enum WSET_TYPES
{
	STATUS_AWAY_WSET,
	STATUS_CDCCCOUNT_WSET,
	STATUS_CHANNEL_WSET,
	STATUS_CHANOP_WSET,
	STATUS_CLOCK_WSET,
	STATUS_CPU_SAVER_WSET,
	STATUS_DCCCOUNT_WSET,
	STATUS_FLAG_WSET,
	STATUS_FORMAT_WSET,
	STATUS_FORMAT1_WSET,
	STATUS_FORMAT2_WSET,
	STATUS_FORMAT3_WSET,
	STATUS_HALFOP_WSET,
	STATUS_HOLD_WSET,
	STATUS_HOLD_LINES_WSET,
	STATUS_LAG_WSET,
	STATUS_MAIL_WSET,
	STATUS_MODE_WSET,
	STATUS_MSGCOUNT_WSET,
	STATUS_NICKNAME_WSET,
	STATUS_NOTIFY_WSET,
	STATUS_OPER_KILLS_WSET,
	STATUS_QUERY_WSET,
	STATUS_SCROLLBACK_WSET,
	STATUS_SERVER_WSET,
	STATUS_TOPIC_WSET,
	STATUS_UMODE_WSET,
	STATUS_USER0_WSET,
	STATUS_USER1_WSET,
	STATUS_USER10_WSET,
	STATUS_USER11_WSET,
	STATUS_USER12_WSET,
	STATUS_USER13_WSET,
	STATUS_USER14_WSET,
	STATUS_USER15_WSET,
	STATUS_USER16_WSET,
	STATUS_USER17_WSET,
	STATUS_USER18_WSET,
	STATUS_USER19_WSET,
	STATUS_USER2_WSET,
	STATUS_USER20_WSET,
	STATUS_USER21_WSET,
	STATUS_USER22_WSET,
	STATUS_USER23_WSET,
	STATUS_USER24_WSET,
	STATUS_USER25_WSET,
	STATUS_USER26_WSET,
	STATUS_USER27_WSET,
	STATUS_USER28_WSET,
	STATUS_USER29_WSET,
	STATUS_USER3_WSET,
	STATUS_USER30_WSET,
	STATUS_USER31_WSET,
	STATUS_USER32_WSET,
	STATUS_USER33_WSET,
	STATUS_USER34_WSET,
	STATUS_USER35_WSET,
	STATUS_USER36_WSET,
	STATUS_USER37_WSET,
	STATUS_USER38_WSET,
	STATUS_USER39_WSET,
	STATUS_USER4_WSET,
	STATUS_USER5_WSET,
	STATUS_USER6_WSET,
	STATUS_USER7_WSET,
	STATUS_USER8_WSET,
	STATUS_USER9_WSET,
	STATUS_USERS_WSET,
	STATUS_VOICE_WSET,
	STATUS_WINDOW_WSET,
	NUMBER_OF_WSETS
};

enum FSET_TYPES
{
FORMAT_ACTION_FSET,
FORMAT_ACTION_AR_FSET,
FORMAT_ACTION_CHANNEL_FSET,
FORMAT_ACTION_OTHER_FSET,
FORMAT_ACTION_OTHER_AR_FSET,
FORMAT_ACTION_USER_FSET,
FORMAT_ACTION_USER_AR_FSET,
FORMAT_ALIAS_FSET,
FORMAT_ASSIGN_FSET,
FORMAT_AWAY_FSET,
FORMAT_BACK_FSET,

FORMAT_BANS_FSET,
FORMAT_BANS_FOOTER_FSET,
FORMAT_BANS_HEADER_FSET,
FORMAT_BITCH_FSET,
FORMAT_BOT_FSET,
FORMAT_BOT_FOOTER_FSET,
FORMAT_BOT_HEADER_FSET,
FORMAT_BWALL_FSET,

FORMAT_CHANNEL_SIGNOFF_FSET,

FORMAT_COMPLETE_FSET,
FORMAT_CONNECT_FSET,
FORMAT_CSET_FSET,
FORMAT_CTCP_FSET,
FORMAT_CTCP_CLOAK_FSET,
FORMAT_CTCP_CLOAK_FUNC_FSET,
FORMAT_CTCP_CLOAK_FUNC_USER_FSET,
FORMAT_CTCP_CLOAK_UNKNOWN_FSET,
FORMAT_CTCP_CLOAK_UNKNOWN_USER_FSET,
FORMAT_CTCP_CLOAK_USER_FSET,
FORMAT_CTCP_FUNC_FSET,
FORMAT_CTCP_FUNC_USER_FSET,
FORMAT_CTCP_REPLY_FSET,
FORMAT_CTCP_UNKNOWN_FSET,
FORMAT_CTCP_UNKNOWN_USER_FSET,
FORMAT_CTCP_USER_FSET,
FORMAT_DCC_FSET,
FORMAT_DCC_CHAT_FSET,
FORMAT_DCC_CONNECT_FSET,
FORMAT_DCC_ERROR_FSET,
FORMAT_DCC_LOST_FSET,
FORMAT_DCC_REQUEST_FSET,
FORMAT_DESYNC_FSET,
FORMAT_DISCONNECT_FSET,
FORMAT_EBANS_FSET,
FORMAT_EBANS_FOOTER_FSET,
FORMAT_EBANS_HEADER_FSET,
FORMAT_ENCRYPTED_NOTICE_FSET,
FORMAT_ENCRYPTED_PRIVMSG_FSET,
FORMAT_FLOOD_FSET,
FORMAT_FRIEND_JOIN_FSET,
FORMAT_HELP_FSET,
FORMAT_HOOK_FSET,

FORMAT_IGNORE_INVITE_FSET,
FORMAT_IGNORE_MSG_FSET,
FORMAT_IGNORE_MSG_AWAY_FSET,
FORMAT_IGNORE_NOTICE_FSET,
FORMAT_IGNORE_WALL_FSET,

FORMAT_INVITE_FSET,
FORMAT_INVITE_USER_FSET,
FORMAT_JOIN_FSET,
FORMAT_KICK_FSET,
FORMAT_KICK_USER_FSET,
FORMAT_KILL_FSET,
FORMAT_LASTLOG_FSET,
FORMAT_LEAVE_FSET,
FORMAT_LINKS_FSET,
FORMAT_LIST_FSET,
FORMAT_MAIL_FSET,
FORMAT_MODE_FSET,
FORMAT_MODE_CHANNEL_FSET,
FORMAT_MSG_FSET,
FORMAT_MSGCOUNT_FSET,
FORMAT_MSGLOG_FSET,
FORMAT_MSG_GROUP_FSET,

FORMAT_NAMES_FSET,
FORMAT_NAMES_BANNER_FSET,
FORMAT_NAMES_BOT_FSET,
FORMAT_NAMES_FOOTER_FSET,
FORMAT_NAMES_FRIEND_FSET,
FORMAT_NAMES_IRCOP_FSET,
FORMAT_NAMES_NICK_FSET,
FORMAT_NAMES_NICK_BOT_FSET,
FORMAT_NAMES_NICK_FRIEND_FSET,
FORMAT_NAMES_NICK_ME_FSET,
FORMAT_NAMES_NICK_SHIT_FSET,
FORMAT_NAMES_NONOP_FSET,
FORMAT_NAMES_OP_FSET,
FORMAT_NAMES_SHIT_FSET,
FORMAT_NAMES_USER_FSET,
FORMAT_NAMES_USER_CHANOP_FSET,
FORMAT_NAMES_USER_IRCOP_FSET,
FORMAT_NAMES_USER_VOICE_FSET,
FORMAT_NAMES_VOICE_FSET,

FORMAT_NETADD_FSET,
FORMAT_NETJOIN_FSET,
FORMAT_NETSPLIT_FSET,
FORMAT_NETSPLIT_HEADER_FSET,

FORMAT_NICKNAME_FSET,
FORMAT_NICKNAME_OTHER_FSET,
FORMAT_NICKNAME_USER_FSET,
FORMAT_NICK_AUTO_FSET,
FORMAT_NICK_COMP_FSET,
FORMAT_NICK_MSG_FSET,

FORMAT_NONICK_FSET,
FORMAT_NOTE_FSET,
FORMAT_NOTICE_FSET,
FORMAT_NOTIFY_OFF_FSET,
FORMAT_NOTIFY_ON_FSET,
FORMAT_NOTIFY_SIGNOFF_FSET,
FORMAT_NOTIFY_SIGNON_FSET,
FORMAT_OPER_FSET,
FORMAT_OV_FSET,
FORMAT_PASTE_FSET,
FORMAT_PUBLIC_FSET,
FORMAT_PUBLIC_AR_FSET,
FORMAT_PUBLIC_MSG_FSET,
FORMAT_PUBLIC_MSG_AR_FSET,
FORMAT_PUBLIC_NOTICE_FSET,
FORMAT_PUBLIC_NOTICE_AR_FSET,
FORMAT_PUBLIC_OTHER_FSET,
FORMAT_PUBLIC_OTHER_AR_FSET,
FORMAT_REL_FSET,
FORMAT_RELM_FSET,
FORMAT_RELN_FSET,
FORMAT_RELS_FSET,
FORMAT_RELSM_FSET,
FORMAT_RELSN_FSET,
FORMAT_SEND_ACTION_FSET,
FORMAT_SEND_ACTION_OTHER_FSET,
FORMAT_SEND_AWAY_FSET,
FORMAT_SEND_CTCP_FSET,
FORMAT_SEND_DCC_CHAT_FSET,
FORMAT_SEND_ENCRYPTED_MSG_FSET,
FORMAT_SEND_ENCRYPTED_NOTICE_FSET,
FORMAT_SEND_MSG_FSET,

FORMAT_SEND_NOTICE_FSET,
FORMAT_SEND_PUBLIC_FSET,
FORMAT_SEND_PUBLIC_OTHER_FSET,
FORMAT_SERVER_FSET,
FORMAT_SERVER_MSG1_FSET,
FORMAT_SERVER_MSG1_FROM_FSET,
FORMAT_SERVER_MSG2_FSET,
FORMAT_SERVER_MSG2_FROM_FSET,

FORMAT_SERVER_NOTICE_FSET,
FORMAT_SERVER_NOTICE_BOT_FSET,
FORMAT_SERVER_NOTICE_BOT1_FSET,
FORMAT_SERVER_NOTICE_BOT_ALARM_FSET,
FORMAT_SERVER_NOTICE_CLIENT_CONNECT_FSET,
FORMAT_SERVER_NOTICE_CLIENT_EXIT_FSET,
FORMAT_SERVER_NOTICE_CLIENT_INVALID_FSET,
FORMAT_SERVER_NOTICE_CLIENT_TERM_FSET,
FORMAT_SERVER_NOTICE_FAKE_FSET,
FORMAT_SERVER_NOTICE_GLINE_FSET,
FORMAT_SERVER_NOTICE_KILL_FSET,
FORMAT_SERVER_NOTICE_KILL_LOCAL_FSET,
FORMAT_SERVER_NOTICE_KLINE_FSET,
FORMAT_SERVER_NOTICE_NICK_COLLISION_FSET,
FORMAT_SERVER_NOTICE_OPER_FSET,
FORMAT_SERVER_NOTICE_REHASH_FSET,
FORMAT_SERVER_NOTICE_STATS_FSET,
FORMAT_SERVER_NOTICE_TRAFFIC_HIGH_FSET,
FORMAT_SERVER_NOTICE_TRAFFIC_NORM_FSET,
FORMAT_SERVER_NOTICE_UNAUTH_FSET,

FORMAT_SET_FSET,
FORMAT_SET_NOVALUE_FSET,
FORMAT_SHITLIST_FSET,
FORMAT_SHITLIST_FOOTER_FSET,
FORMAT_SHITLIST_HEADER_FSET,

FORMAT_SIGNOFF_FSET,
FORMAT_SILENCE_FSET,
FORMAT_SMODE_FSET,
FORMAT_STATUS_FSET,
FORMAT_STATUS1_FSET,
FORMAT_STATUS2_FSET,
FORMAT_STATUS3_FSET,
FORMAT_TIMER_FSET,
FORMAT_TOPIC_FSET,
FORMAT_TOPIC_CHANGE_FSET,
FORMAT_TOPIC_CHANGE_HEADER_FSET,
FORMAT_TOPIC_SETBY_FSET,
FORMAT_TOPIC_UNSET_FSET,
FORMAT_TRACE_OPER_FSET,
FORMAT_TRACE_SERVER_FSET,
FORMAT_TRACE_USER_FSET,
FORMAT_USAGE_FSET,
FORMAT_USERLIST_FSET,
FORMAT_USERLIST_FOOTER_FSET,
FORMAT_USERLIST_HEADER_FSET,

FORMAT_USERMODE_FSET,
FORMAT_USERS_FSET,
FORMAT_USERS_HEADER_FSET,
FORMAT_USERS_SHIT_FSET,
FORMAT_USERS_TITLE_FSET,
FORMAT_USERS_USER_FSET,
FORMAT_VERSION_FSET,
FORMAT_WALL_FSET,
FORMAT_WALLOP_FSET,
FORMAT_WALL_AR_FSET,
FORMAT_WATCH_SIGNOFF_FSET,
FORMAT_WATCH_SIGNON_FSET,
FORMAT_WHO_FSET,
FORMAT_WHOIS_ADMIN_FSET,
FORMAT_WHOIS_AWAY_FSET,
FORMAT_WHOIS_BOT_FSET,
FORMAT_WHOIS_CHANNELS_FSET,
FORMAT_WHOIS_FOOTER_FSET,
FORMAT_WHOIS_FRIEND_FSET,
FORMAT_WHOIS_HEADER_FSET,
FORMAT_WHOIS_HELP_FSET,
FORMAT_WHOIS_IDLE_FSET,
FORMAT_WHOIS_NAME_FSET,
FORMAT_WHOIS_NICK_FSET,
FORMAT_WHOIS_OPER_FSET,
FORMAT_WHOIS_REGISTER_FSET,
FORMAT_WHOIS_SERVER_FSET,
FORMAT_WHOIS_SERVICE_FSET,
FORMAT_WHOIS_SHIT_FSET,
FORMAT_WHOIS_SIGNON_FSET,
FORMAT_WHOIS_ACTUALLY_FSET,
FORMAT_WHOLEFT_FOOTER_FSET,
FORMAT_WHOLEFT_HEADER_FSET,
FORMAT_WHOLEFT_USER_FSET,
FORMAT_WHOWAS_HEADER_FSET,
FORMAT_WHOWAS_NICK_FSET,
FORMAT_WIDELIST_FSET,
FORMAT_WINDOW_SET_FSET,
FORMAT_XTERM_TITLE_FSET,
NUMBER_OF_FSET
};

void		cset_variable(char *, char *, char *, char *);
int		BX_get_cset_int_var(CSetList *, int);
void		BX_set_cset_int_var(CSetList *, int, int);
char		*BX_get_cset_str_var(CSetList *, int);
void		BX_set_cset_str_var(CSetList *, int, char *);

CSetList	*create_csets_for_channel(char *channel);
void		remove_csets_for_channel(CSetList *);
char		*BX_get_wset_string_var(WSet *, int);
void		BX_set_wset_string_var(WSet *, int, char *);
void		wset_variable(char *, char *, char *, char *);
WSet		*create_wsets_for_window(Window *);
void		create_fsets(Window *, int);
void		remove_wsets_for_window(Window *);
char		*BX_fget_string_var(enum FSET_TYPES);
/* XXX */
char		*fget_string_var(enum FSET_TYPES);
void		BX_fset_string_var(enum FSET_TYPES, char *);
void		fset_variable(const char *, char *, const char *);
char		*make_fstring_var(const char *);
char		**get_wset_format_var_address(WSet *, int);
//char		*get_cset(char *, ChannelList *, char *);
void		delete_all_ext_fset(void);
CSetList	*check_cset_queue(char *, int);
//void		do_logchannel(unsigned long, ChannelList *, char *, ...);
//void		check_channel_limit(ChannelList *chan);

void add_numeric_fset(char *name, int remove, char *args, int);
char *find_numeric_fset(int numeric);

#endif /* _CSETS_H_ */
