#include "header.h"
#include "variables.h"
char OLDPWD[2000] = "", HOME[2000];
char *internal_commands[] = { 
        "cd", "bg", "fg", "overkill", "kjob", "jobs", "pwd", "ls", "echo", "pinfo", "quit", "nightswatch", "setenv", "unsetenv"
};
jobs job[1010];
int file_in = 0;
int file_out = 1;
int background_jobs = 0;
int shell_setpgid;
jobs child_pid;
int num_of_internal(){
    return sizeof(internal_commands)/ sizeof(char *);
}

int execute_exit(){
    return 0;
}

int main()
{
    getcwd(HOME, sizeof(HOME));
    shell_loop();
    return 0;
}

