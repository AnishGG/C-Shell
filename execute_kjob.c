#include"header.h"
#include"variables.h"

int execute_kjob(char **args, int flag)
{
    if(args[0] == NULL || args[1] == NULL || args[2] == NULL){
        printf("Usage: kjob [jobNumber] [signalNumber]\n");
    }
    else{
        int idx = atoi(args[1]);
        if(idx > background_jobs){
            printf("Job does not exist\nRun \"jobs\" for all background processes\n");
        }
        else{
            kill(job[idx].pid, atoi(args[2]));    // This will send a signal to the process
            if(atoi(args[2]) == 9){         // In this case job must be deleted from the array and no. of jobs are decreased
                pop_job(idx);
            }
        }
    }
    return 1;
}
