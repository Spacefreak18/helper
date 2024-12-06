#ifndef _PARAMETERS_H
#define _PARAMETERS_H

#include <stdbool.h>

typedef struct
{
    int   program_action;
    int verbosity_count;
    bool user_specified_log_file;

    char* log_filename_str;
    char* log_fullfilename_str;
    char* log_dirname_str;
}
Parameters;

typedef enum
{
    A_PLAY          = 0,
    A_TEST          = 1,
    A_CONFIG_TACH   = 2,
    A_CONFIG_SHAKER = 3
}
ProgramAction;

typedef enum
{
    E_SUCCESS_AND_EXIT = 0,
    E_SUCCESS_AND_DO   = 1,
    E_SOMETHING_BAD    = 2
}
ConfigError;

int freeparams(Parameters* p);
ConfigError getParameters(int argc, char** argv, Parameters* p);

struct _errordesc
{
    int  code;
    char* message;
} static errordesc[] =
{
    { E_SUCCESS_AND_EXIT, "No error and exiting" },
    { E_SUCCESS_AND_DO,   "No error and continuing" },
    { E_SOMETHING_BAD,    "Something bad happened" },
};

#endif
