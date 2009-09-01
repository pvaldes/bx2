/*
 * vars.h: header for vars.c
 *
 * Copyright 1990, 1995 Michael Sandroff, Matthew Green and others.
 * Copyright 1997 EPIC Software Labs
 */

#ifndef __vars_h__
#define __vars_h__

/* indexes for the irc_variable array */
/*
enum VAR_TYPES {
*/

#ifndef VARS_C
extern
#endif

int	AINV_VAR,
	ALLOW_C1_CHARS_VAR,
	ALTNICK_VAR,
	ALWAYS_SPLIT_BIGGEST_VAR,
	ANNOY_KICK_VAR,
	AOP_VAR,
	APPEND_LOG_VAR,
	AUTOKICK_ON_VERSION_VAR,
	AUTO_AWAY_VAR,
	AUTO_AWAY_TIME_VAR,
	AUTO_JOIN_ON_INVITE_VAR,
	AUTO_LIMIT_VAR,
	AUTO_NSLOOKUP_VAR,
	AUTO_RECONNECT_VAR,
	AUTO_REJOIN_VAR,
	AUTO_RESPONSE_VAR,
	AUTO_RESPONSE_STR_VAR,
	AUTO_UNBAN_VAR,
	AUTO_UNMARK_AWAY_VAR,
	AUTO_WHOWAS_VAR,
	BANNER_VAR,
	BANNER_EXPAND_VAR,
	BANTIME_VAR,
	BEEP_VAR,
	BEEP_ALWAYS_VAR,
	BEEP_MAX_VAR,
	BEEP_ON_MSG_VAR,
	BEEP_WHEN_AWAY_VAR,
	BITCH_VAR,
	BITCHX_HELP_VAR,
	BLINK_VIDEO_VAR,
	BOLD_VIDEO_VAR,
	BOT_LOG_VAR,
	BOT_LOGFILE_VAR,
	BOT_MODE_VAR,
	BOT_PASSWD_VAR,
	BOT_RETURN_VAR,
	BOT_TCL_VAR,
	CDCC_VAR,
	CDCC_FLOOD_AFTER_VAR,
	CDCC_FLOOD_RATE_VAR,
	CDCC_PROMPT_VAR,
	CDCC_SECURITY_VAR,
	CD_DEVICE_VAR,
	CHANGE_NICK_ON_KILL_VAR,
	CHANMODE_VAR,
	CHANNEL_NAME_WIDTH_VAR,
	CHECK_BEEP_USERS_VAR,
	CLIENT_INFORMATION_VAR,
	CLOAK_VAR,
	CLOCK_VAR,
	CLOCK_24HOUR_VAR,
	CLOCK_FORMAT_VAR,
	CLOCK_INTERVAL_VAR,
	CLONE_CHECK_VAR,
	CLONE_COUNT_VAR,
	CMDCHARS_VAR,
	COLOR_VAR,
	COMMAND_MODE_VAR,
	COMMENT_BREAKAGE_VAR,
	COMMENT_HACK_VAR,
	COMPRESS_MODES_VAR,
	CONNECT_DELAY_VAR,
	CONNECT_TIMEOUT_VAR,
	CONTINUED_LINE_VAR,
	CPU_SAVER_AFTER_VAR,
	CPU_SAVER_EVERY_VAR,
	CTCP_DELAY_VAR,
	CTCP_FLOOD_AFTER_VAR,
	CTCP_FLOOD_BAN_VAR,
	CTCP_FLOOD_PROTECTION_VAR,
	CTCP_FLOOD_RATE_VAR,
	CTCP_VERBOSE_VAR,
	CTOOLZ_DIR_VAR,
	CURRENT_WINDOW_LEVEL_VAR,
	DCC_AUTO_SEND_REJECTS_VAR,
	DCC_AUTOGET_VAR,
	DCC_AUTORENAME_VAR,
	DCC_AUTORESUME_VAR,
	DCC_BAR_TYPE_VAR,
	DCC_BLOCK_SIZE_VAR,
	DCC_CONNECT_TIMEOUT_VAR,
	DCC_DEQUOTE_FILENAMES_VAR,
	DCC_DLDIR_VAR,
	DCC_FAST_VAR,
	DCC_FORCE_PORT_VAR,
	DCC_GET_LIMIT_VAR,
	DCC_MAX_AUTOGET_SIZE_VAR,
	DCC_QUEUE_LIMIT_VAR,
	DCC_LONG_PATHNAMES_VAR,
	DCC_SEND_LIMIT_VAR,
	DCC_SLIDING_WINDOW_VAR,
	DCC_STORE_PATH_VAR,
	DCC_TIMEOUT_VAR,
	DCC_ULDIR_VAR,
	DCC_USE_GATEWAY_ADDR_VAR,
	DEBUG_VAR,
	DEFAULT_CODEPAGE_VAR,
	DEFAULT_FONT_VAR,
	DEFAULT_MENU_VAR,
	DEFAULT_NICK_VAR,
	DEFAULT_REALNAME_VAR,
	DEFAULT_REASON_VAR,
	DEFAULT_USERNAME_VAR,
	DEOPFLOOD_VAR,
	DEOPFLOOD_TIME_VAR,
	DEOP_ON_DEOPFLOOD_VAR,
	DEOP_ON_KICKFLOOD_VAR,
	DISPATCH_UNKNOWN_COMMANDS_VAR,
	DISPLAY_VAR,
	DISPLAY_ANSI_VAR,
	DISPLAY_PC_CHARACTERS_VAR,
	DO_NOTIFY_IMMEDIATELY_VAR,
	DOUBLE_STATUS_LINE_VAR,
	EIGHT_BIT_CHARACTERS_VAR,
	EXEC_PROTECTION_VAR,
	FAKE_SPLIT_PATTERNS_VAR,
	FLOATING_POINT_MATH_VAR,
	/* XXX This isn't a typo, bx has a "FLOATING_POINT_MATH_VAR". */
	FLOATING_POINT_MATH_VAR_VAR,
	FLOATING_POINT_PRECISION_VAR,
	FLOOD_AFTER_VAR,
	FLOOD_IGNORE_VAR,
	FLOOD_KICK_VAR,
	FLOOD_MASKUSER_VAR,
	FLOOD_PROTECTION_VAR,
	FLOOD_RATE_VAR,
	FLOOD_RATE_PER_VAR,
	FLOOD_USERS_VAR,
	FLOOD_WARNING_VAR,
	FTP_GRAB_VAR,
	FULL_STATUS_LINE_VAR,
	HACKING_VAR,
	HACK_OPS_VAR,
	HEBREW_TOGGLE_VAR,
	HELP_PAGER_VAR,
	HELP_PATH_VAR,
	HELP_PROMPT_VAR,
	HELP_WINDOW_VAR,
	HIDE_PRIVATE_CHANNELS_VAR,
	HIGHLIGHT_CHAR_VAR,
	HIGH_BIT_ESCAPE_VAR,
	HISTORY_VAR,
	HOLD_MODE_VAR,
	HOLD_MODE_MAX_VAR,
	HOLD_SLIDER_VAR,
	HTTP_GRAB_VAR,
	IDENT_HACK_VAR,
	IDLE_CHECK_VAR,
	IGNORE_TIME_VAR,
	INDENT_VAR,
	INPUT_ALIASES_VAR,
	INPUT_GLOB_VAR,
	INPUT_INDICATOR_LEFT_VAR,
        INPUT_INDICATOR_RIGHT_VAR,
	INPUT_PROMPT_VAR,
	INSERT_MODE_VAR,
	INVERSE_VIDEO_VAR,
	JOINFLOOD_VAR,
	JOINFLOOD_TIME_VAR,
	JOIN_NEW_WINDOW_VAR,
	JOIN_NEW_WINDOW_TYPE_VAR,
	KEY_INTERVAL_VAR,
	KICKFLOOD_VAR,
	KICKFLOOD_TIME_VAR,
	KICK_IF_BANNED_VAR,
	KICK_ON_DEOPFLOOD_VAR,
	KICK_ON_JOINFLOOD_VAR,
	KICK_ON_KICKFLOOD_VAR,
	KICK_ON_NICKFLOOD_VAR,
	KICK_ON_PUBFLOOD_VAR,
	KICK_OPS_VAR,
	LAMEIDENT_VAR,
	LAMELIST_VAR,
	LASTLOG_VAR,
	LASTLOG_ANSI_VAR,
	LASTLOG_LEVEL_VAR,
	LASTLOG_REWRITE_VAR,
	LLOOK_VAR,
	LLOOK_DELAY_VAR,
	LOAD_PATH_VAR,
	LOG_VAR,
	LOGFILE_VAR,
	LOG_REWRITE_VAR,
	MAIL_VAR,
	MAIL_INTERVAL_VAR,
	MAIL_TYPE_VAR,
	MANGLE_DISPLAY_VAR,
	MANGLE_INBOUND_VAR,
	MANGLE_LOGFILES_VAR,
	MANGLE_OPERLOG_VAR,
	MANGLE_OUTBOUND_VAR,
	MAX_DEOPS_VAR,
	MAX_IDLEKICKS_VAR,
	MAX_SERVER_RECONNECT_VAR,
	MAX_URLS_VAR,
	MDI_VAR,
	/* XXX This isn't a typo, bx has a "META_STATES_VAR". */
	META_STATES_VAR_VAR,
	METRIC_TIME_VAR,
	MIRC_BROKEN_DCC_RESUME_VAR,
	MIRCS_VAR,
	MODE_STRIPPER_VAR,
	MSGCOUNT_VAR,
	MSGLOG_VAR,
	MSGLOG_FILE_VAR,
	MSGLOG_LEVEL_VAR,
	NAMES_COLUMNS_VAR,
	NAT_ADDRESS_VAR,
	ND_SPACE_MAX_VAR,
	NEW_SERVER_LASTLOG_LEVEL_VAR,
	NEXT_SERVER_ON_LOCAL_KILL_VAR,
	NICKFLOOD_VAR,
	NICKFLOOD_TIME_VAR,
	NICKLIST_VAR,
	NICKLIST_SORT_VAR,
	NICK_COMPLETION_VAR,
	NICK_COMPLETION_CHAR_VAR,
	NICK_COMPLETION_LEN_VAR,
	NICK_COMPLETION_TYPE_VAR,
	NOTIFY_VAR,
	NOTIFY_HANDLER_VAR,
	NOTIFY_INTERVAL_VAR,
	NOTIFY_LEVEL_VAR,
	NOTIFY_ON_TERMINATION_VAR,
	NOTIFY_USERHOST_AUTOMATIC_VAR,
	NO_CONTROL_LOG_VAR,
	NO_CTCP_FLOOD_VAR,
	NO_FAIL_DISCONNECT_VAR,
	NUM_BANMODES_VAR,
	NUM_KICKS_VAR,
	NUM_KILLS_VAR,
	NUM_OF_WHOWAS_VAR,
	NUM_OPMODES_VAR,
	OLD_MATH_PARSER_VAR,
	OLD_SERVER_LASTLOG_LEVEL_VAR,
	OPER_MODES_VAR,
	ORIGNICK_TIME_VAR,
	OUTPUT_REWRITE_VAR,
	OV_VAR,
	PAD_CHAR_VAR,
	PING_TYPE_VAR,
	PROTECT_CHANNELS_VAR,
	PUBFLOOD_VAR,
	PUBFLOOD_TIME_VAR,
	QUERY_NEW_WINDOW_VAR,
	QUERY_NEW_WINDOW_TYPE_VAR,
	QUEUE_SENDS_VAR,
	QUIT_MESSAGE_VAR,
	RANDOM_LOCAL_PORTS_VAR,
	RANDOM_SOURCE_VAR,
	REALNAME_VAR,
	REVERSE_STATUS_VAR,
	SAVEFILE_VAR,
	SCREEN_OPTIONS_VAR,
	SCRIPT_HELP_VAR,
	SCROLLBACK_VAR,
	SCROLLBACK_RATIO_VAR,
	SCROLL_LINES_VAR,
	SEND_AWAY_MSG_VAR,
	SEND_CTCP_MSG_VAR,
	SEND_IGNORE_MSG_VAR,
	SEND_OP_MSG_VAR,
	SERVER_GROUPS_VAR,
	SERVER_PROMPT_VAR,
	SHELL_VAR,
	SHELL_FLAGS_VAR,
	SHELL_LIMIT_VAR,
	SHITLIST_VAR,
	SHITLIST_REASON_VAR,
	SHOW_AWAY_ONCE_VAR,
	SHOW_CHANNEL_NAMES_VAR,
	SHOW_END_OF_MSGS_VAR,
	SHOW_NUMERICS_VAR,
	SHOW_NUMERICS_STR_VAR,
	SHOW_STATUS_ALL_VAR,
	SHOW_WHO_HOPCOUNT_VAR,
	SOCKS_HOST_VAR,
	SOCKS_PORT_VAR,
	STATUS_AWAY_VAR,
	STATUS_CDCCCOUNT_VAR,
	STATUS_CHANNEL_VAR,
	STATUS_CHANOP_VAR,
	STATUS_CLOCK_VAR,
	STATUS_CPU_SAVER_VAR,
	STATUS_DCCCOUNT_VAR,
	STATUS_DOES_EXPANDOS_VAR,
	STATUS_FLAG_VAR,
	STATUS_FORMAT_VAR,
	STATUS_FORMAT1_VAR,
	STATUS_FORMAT2_VAR,
	STATUS_FORMAT3_VAR,
	STATUS_HALFOP_VAR,
	STATUS_HOLD_VAR,
	STATUS_HOLD_LINES_VAR,
	STATUS_HOLDMODE_VAR,
	STATUS_INSERT_VAR,
	STATUS_LAG_VAR,
	STATUS_MAIL_VAR,
	STATUS_MODE_VAR,
	STATUS_MSGCOUNT_VAR,
	STATUS_NICK_VAR,
	STATUS_NICKNAME_VAR,
	STATUS_NOSWAP_VAR,
	STATUS_NOTIFY_VAR,
	STATUS_NO_REPEAT_VAR,
	STATUS_OPER_VAR,
	STATUS_OPER_KILLS_VAR,
	STATUS_OVERWRITE_VAR,
	STATUS_QUERY_VAR,
	STATUS_SCROLLBACK_VAR,
	STATUS_SERVER_VAR,
	STATUS_SSL_OFF_VAR,
	STATUS_SSL_ON_VAR,
	STATUS_TOPIC_VAR,
	STATUS_UMODE_VAR,
	STATUS_USER_VAR,
	STATUS_USER0_VAR,
	STATUS_USER1_VAR,
	STATUS_USER10_VAR,
	STATUS_USER11_VAR,
	STATUS_USER12_VAR,
	STATUS_USER13_VAR,
	STATUS_USER14_VAR,
	STATUS_USER15_VAR,
	STATUS_USER16_VAR,
	STATUS_USER17_VAR,
	STATUS_USER18_VAR,
	STATUS_USER19_VAR,
	STATUS_USER2_VAR,
	STATUS_USER20_VAR,
	STATUS_USER21_VAR,
	STATUS_USER22_VAR,
	STATUS_USER23_VAR,
	STATUS_USER24_VAR,
	STATUS_USER25_VAR,
	STATUS_USER26_VAR,
	STATUS_USER27_VAR,
	STATUS_USER28_VAR,
	STATUS_USER29_VAR,
	STATUS_USER3_VAR,
	STATUS_USER30_VAR,
	STATUS_USER31_VAR,
	STATUS_USER32_VAR,
	STATUS_USER33_VAR,
	STATUS_USER34_VAR,
	STATUS_USER35_VAR,
	STATUS_USER36_VAR,
	STATUS_USER37_VAR,
	STATUS_USER38_VAR,
	STATUS_USER39_VAR,
	STATUS_USER4_VAR,
	STATUS_USER5_VAR,
	STATUS_USER6_VAR,
	STATUS_USER7_VAR,
	STATUS_USER8_VAR,
	STATUS_USER9_VAR,
	STATUS_USERS_VAR,
	STATUS_VOICE_VAR,
	STATUS_WINDOW_VAR,
	SUPPRESS_FROM_REMOTE_SERVER_VAR,
	SUPPRESS_SERVER_MOTD_VAR,
	SWATCH_VAR,
	SWITCH_CHANNELS_BETWEEN_WINDOWS_VAR,
	TAB_VAR,
	TAB_MAX_VAR,
	TERM_DOES_BRIGHT_BLINK_VAR,
	TIMESTAMP_VAR,
	TIMESTAMP_AWAYLOG_HOURLY_VAR,
	TIMESTAMP_STRING_VAR,
	TRANSLATION_VAR,
	TRANSLATION_PATH_VAR,
	UNDERLINE_VIDEO_VAR,
	USERLIST_VAR,
	USERMODE_VAR,
	USER_FLAG_OPS_VAR,
	USER_FLAG_PROT_VAR,
	USER_INFORMATION_VAR,
	WINDOW_DESTROY_PART_VAR,
	WINDOW_QUIET_VAR,
	WORD_BREAK_VAR,
	WSERV_PATH_VAR,
	WSERV_TYPE_VAR,
	XTERM_VAR,
	XTERM_OPTIONS_VAR,
	XTERM_TITLE_VAR,
	NUMBER_OF_VARIABLES
/* } */ ;

/* var_settings indexes ... also used in display.c for highlights */
#define OFF 			0
#define ON 			1
#define TOGGLE 			2

#define	DEBUG_COMMANDS		0x0001
#define	DEBUG_EXPANSIONS	0x0002
#define DEBUG_FUNCTIONS		0x0004

typedef union builtin_variable {
        char *  string;                 /* string value of variable */
        int     integer;                /* int value of variable */
} VARIABLE;

/* the types of IrcVariables */
#define STR_VAR 	0
#define INT_VAR 	1
#define CHAR_VAR 	2
#define BOOL_VAR 	3

/* IrcVariable: structure for each variable in the variable table */
typedef struct
{
        int             type;           /* variable types, see below */
        VARIABLE *      data;           /* The value of the variable */
        void    (*func) (void *); 	/* func called when var is set */
	char *		script;		/* script called when var is set */
        unsigned short  flags;          /* flags for this variable */
}       IrcVariable;



	BUILT_IN_COMMAND(setcmd);

	int	do_boolean 		(char *, int *);
	int	do_short_boolean 	(char *, short *);
	int	get_int_var 		(int);
	char *	get_string_var 		(int);
	void	set_var_value		(int, const char *, int);
	int	is_var_builtin		(const char *);
	void	init_variables_stage1	(void);
	void	init_variables_stage2	(void);
	char*	make_string_var 	(const char *);
	int	charset_size 		(void);
	void	save_variables 		(FILE *, int);
	void	do_stack_set		(int, char *);
	int	parse_mangle		(const char *, int, char **);
	char	*get_set		(const char *);
	char *	make_string_var_bydata	(int, void *);
	int	set_variable		(const char *, IrcVariable *, const char *, int);
	IrcVariable *   clone_biv	(IrcVariable *);
	void	unclone_biv		(const char *, IrcVariable *);

#endif /* _VARS_H_ */
