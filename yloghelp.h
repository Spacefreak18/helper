#ifndef _YLOGHELP_H
#define _YLOGHELP_H

#define ylogi(...) y_log_message(Y_LOG_LEVEL_INFO, __VA_ARGS__)
#define ylogd(...) y_log_message(Y_LOG_LEVEL_DEBUG, __VA_ARGS__)

#endif
