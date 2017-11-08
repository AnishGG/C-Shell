#include"header.h"
#include"variables.h"

void pop_job(int idx){
    int i;
    for(i = idx;i < background_jobs - 1; i++){
        job[i] = job[i+1];
    }
    background_jobs--;
}
