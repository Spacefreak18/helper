#include "parameters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#include <argtable2.h>

int freeparams(Parameters* p)
{
    if(p->log_filename_str != NULL)
    {
        free(p->log_filename_str);
    }
    if(p->log_fullfilename_str != NULL)
    {
        free(p->log_fullfilename_str);
    }
    if(p->log_dirname_str != NULL)
    {
        free(p->log_dirname_str);
    }
    return 0;
}

ConfigError getParameters(int argc, char** argv, Parameters* p)
{

    ConfigError exitcode = E_SOMETHING_BAD;

    const char* progname = "advent";
    p->part2 = 0;

    struct arg_lit* arg_part2   = arg_litn("p","part", 0, 1, "enable or run part 2");

    struct arg_lit* arg_verbosity   = arg_litn("v","verbose", 0, 2, "increase logging verbosity");
    struct arg_file* arg_log         = arg_filen("l", "log", "<log_file>", 0, 1, NULL);
    struct arg_lit* help             = arg_litn(NULL,"help", 0, 1, "print this help and exit");
    struct arg_lit* vers             = arg_litn(NULL,"version", 0, 1, "print version information and exit");
    struct arg_end* end             = arg_end(20);
    void* argtable[]                = {arg_part2,arg_verbosity,arg_log,help,vers,end};
    int nerrors;


    if (arg_nullcheck(argtable) != 0)
    {
        printf("%s: insufficient memory\n",progname);
        goto cleanup;
    }
    if (arg_nullcheck(argtable) != 0)
    {
        printf("%s: insufficient memory\n",progname);
        goto cleanup;
    }
    if (arg_nullcheck(argtable) != 0)
    {
        printf("%s: insufficient memory\n",progname);
        goto cleanup;
    }


    nerrors = arg_parse(argc,argv,argtable);

    if (nerrors==0)
    {
        p->program_action = A_PLAY;
        p->verbosity_count = arg_verbosity->count;

        if(arg_log->count > 0)
        {
            char* filename = strdup(arg_log->filename[0]);
            p->log_fullfilename_str = strdup(arg_log->filename[0]);
            p->log_filename_str = strdup(arg_log->basename[0]);
            char* dname;
            dname = dirname(filename);
            p->log_dirname_str = strdup(dname);
            p->user_specified_log_file = true;
            free(filename);
        }
        if(arg_part2->count > 0)
        {
            p->part2++;
        }
        exitcode = E_SUCCESS_AND_DO;
    }

    // interpret some special cases before we go through trouble of reading the config file
    if (help->count > 0)
    {
        printf("Usage: %s\n", progname);
        exitcode = E_SUCCESS_AND_EXIT;
        goto cleanup;
    }

    if (vers->count > 0)
    {
        printf("%s Advent of Code - Based Edition\n",progname);
        printf("December 2024, Paul Dino Jones\n");
        exitcode = E_SUCCESS_AND_EXIT;
        goto cleanup;
    }

cleanup:
    arg_freetable(argtable,sizeof(argtable)/sizeof(argtable[0]));
    return exitcode;

}
