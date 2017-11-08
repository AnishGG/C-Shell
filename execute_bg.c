#include"header.h"
#include"variables.h"

int execute_bg(char **args){
    if(args[1] != NULL){
        int idx = atoi(args[1]);
        if(idx >= background_jobs || idx < 0){
            printf("Specified job does not exist\nRun \"jobs\" for all background processes\n");
        }
        else if(string_compare(job[idx].status, "Stopped") == 0){
            printf("Process not stopped in background\n");
        }
        else{
            if(kill(job[idx].pid, SIGCONT) < 0){
                perror("kill(SIGCONT)");
                return 1;
            }
            printf("Process started in background\n");
            strcpy(job[idx].status, "Running");
            return 1;
        }
    }
    else{
        printf("Usage: bg [job number]\n");
    }
    return 1;
}
