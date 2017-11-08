#include"header.h"
#include"variables.h"

int execute_fg(char **args){
    int status;
    if(args[1] != NULL){
        int idx = atoi(args[1]);
        if(idx >= background_jobs || idx < 0)
            printf("Specified job does not exist\nRun \"jobs\" for all background processes\n");
        else{
            if(kill(job[idx].pid, SIGCONT) < 0){
                perror("kill(SIGCONT)");    // sending a signal to run in foreground
                return 1;
            }
            int chd_pid = job[idx].pid;
            pop_job(idx);
            printf("Process in foreground\n");
            //signal(SIGINT, proc_exit);
			//wait(NULL);
            waitpid(chd_pid, NULL, WCONTINUED & 0);
            return 1;
        }
    }
    else{
        printf("Usage: fg [job number]\n");
        return 1;
    }
    return 1;
}
