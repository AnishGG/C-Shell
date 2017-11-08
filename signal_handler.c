#include"header.h"
#include"variables.h"

void signal_handler(int mysig)
{
	if (mysig == SIGTSTP)
	{
        kill(child_pid.pid, SIGSTOP);
        job[background_jobs++] = child_pid;
        /*int pid = fork();
        if(pid == 0){
        //    kill(getpid(), SIGSTOP);
            shell_loop();
        }
        else if(pid > 0){
            wait(NULL);
            exit(0);
        }
        else{
            perror("fork");
        }*/
        //kill(getpid(), SIGSTOP);
		fflush(stdout);
	}
	if (mysig == SIGINT )
	{
		printf("\n");
		printhome();	
		fflush(stdout);
	}
	if (mysig == SIGQUIT)
	{
		printf("ctrld\n");
		fflush(stdout);
	}
}
