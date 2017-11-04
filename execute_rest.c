#include"header.h"
#include"variables.h"

void proc_exit()
{
        //int wstat;
        union wait wstat;
        pid_t   pid;

        while (1) {
            pid = wait3 (&wstat, WNOHANG, (struct rusage *)NULL );
            if (pid == 0)
                return;
            else if (pid == -1)
                return;
            else if (wstat.w_retcode == 0)
            {
                printf ("pid:%d Return code: %d\n",pid, wstat.w_retcode);
            }
        }
}

int execute_rest(char **args, int flag){
	int fd[2];
	pipe(fd);
    int i = 0, background = 0, status;
    while(args[i]){     // & can only be applied at last of the process
        i++;
    }
	signal (SIGCHLD, proc_exit);
	int ret = fork();
	if (ret == 0)
		exit(rand());
	else if (ret == -1)
	{
		perror("main: fork");
		exit(0);
	}
	else
		pause();
    if(string_compare(args[i-1], "&")){
        background = 1;
        args[i-1] = NULL;
    }
    pid_t pid = fork();
    if(pid == 0){    // means if it is the child process
        // Everything happens only here, after this gets executed, the dup2 are restored as earlier.
        if (file_in != 0)
    	{
        	dup2(file_in,0);
        	close(file_in);
    	}
    	if (file_out != 1)
    	{
        	dup2(file_out,1);
        	close(file_out);
    	}
    	if (flag)
    	{
    		dup2(fd[1],1);				// the command output is in fd[1], after this process exits, stdout remains 1 only
    		close(fd[1]);				
    	}
        if(execvp(args[0], args) == -1){
            fprintf(stderr, "%s: command not found\n", args[0]);
            exit(0);   // means stop this child process
        }
        exit(0);
    }   
    else if(pid > 0){   // this is the parent process
        if(background == 0){
            //printf("%s entered", args[0]);
            //while(wait(&status) != pid);
            wait(NULL);
            //printf("%s exited", args[0]);
        }
        else
        {
            printf("[%d]\n", pid);
        }
        file_in = fd[0];            // Getting file_in , to use input for next command
        close(fd[1]);
    }
    else{
        fprintf(stderr, "%s: forking not done properly\n", args[0]);
    }
    return 1;
}
