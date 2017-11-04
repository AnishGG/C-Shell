#include "header.h"
#include "variables.h"
char OLDPWD[2000] = "", HOME[2000];
char *internal_commands[] = { 
        "cd", "pwd", "ls", "echo", "pinfo", "exit", "nightswatch"
};
jobs job[1010];
int file_in = 0;
int file_out = 1;
int background_jobs = 0;
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

