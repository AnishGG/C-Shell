#include"header.h"
#include"variables.h"

int execute_setenv(char ** args, int flag)
{
	int saved_stduot = dup(1);
    int fd[2];
    pipe(fd);
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
        dup2(fd[1],1);
        close(fd[1]);
    }

    int i = 0;
    while (args[i])
    {
    	i++;
    }
    if (i==1 || i>3)
    {
    	fprintf(stderr,"Invalid arguements: give 1 or 2 arguements\n");
    }
    if (i==2)
    {
    	// 1 for overwrite
    	setenv(args[1],"",1);
    }
    else if (i==3)	
    {
    	setenv(args[1],args[2],1);
    }


    file_in = fd[0];
    close(fd[1]);
    dup2(saved_stduot,1);
    return 1;
}