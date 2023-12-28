#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>

#define MY_STRING_LIMIT 40

/**
 * @brief
 *
 * This partially generated using ChatGPT at https://chat.openai.com/ with prompts
 * including prompt:
 *
 * " main routine in c to validate an input string as arg 1"
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{

    FILE *writefile;
    char filepath[MY_STRING_LIMIT];
    char writestring[MY_STRING_LIMIT];
    int size = 0;
 
    if (argc < 3)
    {
        printf("Usage: %s <writefile> <writestring>\n", argv[0]);
        return EXIT_FAILURE;
    }

    openlog("myprogram", LOG_PID, LOG_LOCAL0);

    strncpy(filepath, argv[1], MY_STRING_LIMIT);
    strncpy(writestring, argv[2], MY_STRING_LIMIT);
    printf("arg1: %s\n", filepath);
    printf("arg2: %s\n", writestring);
    
    writefile = fopen(filepath, "w");
    if (writefile == NULL) {
        syslog(LOG_ERR, "Error opening %s\n", filepath);
        perror("fopen step");
        exit(1);
    }

    size = fprintf(writefile, "%s", writestring);

    if (size <= 0) {
        syslog(LOG_ERR, "Error writing to file %s\n", filepath);
        perror("writing step");
        exit(1);
    }

    if (fclose(writefile)) {
        syslog(LOG_PERROR, "fclose");
        exit(1);
    }

    syslog(LOG_INFO, "Success!\n");
    closelog(); /*man page says optional*/ 
    exit(0); 


}

