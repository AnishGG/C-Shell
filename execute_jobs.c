#include"variables.h"
#include"header.h"
int execute_jobs(int flag)
{
    if(background_jobs == 0){
        printf("There is no background process running\n");
    }
    for(int i = 0;i < background_jobs; i++){
/*        if(job[i].flag == 1)
            strcpy(job[i].status, "Running");
        else
            strcpy(job[i].status, "Stopped");
            */
        printf("[%d] %s  %s [%d]\n", i, job[i].status, job[i].name, job[i].pid);
    }
    return 1;
}
