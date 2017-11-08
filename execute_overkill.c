#include"header.h"
#include"variables.h"

int execute_overkill(int flag)
{
    if(background_jobs < 1){
        printf("No Background Jobs running\n");
    }
    else{
        for(int i = background_jobs - 1;i >= 0; i--){
            kill(job[i].pid, 9);
            pop_job(i);
        }
    }
    background_jobs = 0;
    return 1;
}
