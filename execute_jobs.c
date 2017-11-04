#include"variables.h"
#include"header.h"
void execute_jobs(){
    if(background_jobs == 0){
        printf("There is no background process running\n");
    }
    for(int i = 0;i < background_jobs; i++){
        printf("[%d] %s  %s [%d]\n", i, job[i].status, job[i].name, job[i].pid);
    }
}
