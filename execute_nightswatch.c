#include"header.h"
#include"variables.h"
int execute_nightswatch(char ** args,int flag)
{
    char * command, *path,q;
    char buf[1024];
    int i = 0, loop_interval = 0, j = 0, firstattempt = 1;
    while (args[i]) i++;
    if (i > 4 || i==3)
    {
        if (i==3 && string_compare(args[1],"-n"))
            fprintf(stderr,"-n requires a number to execute nightswatch");
        else    fprintf(stderr,"invalid set of arguements");
        return 1;
    }
    if (i==4 && string_compare(args[1],"-n"))
    {
        for (j=0;j<strlen(args[2]);j++)
            loop_interval = loop_interval*10 + (args[2][j]-'0');
        command = args[3];
    }
    else    
    {
        loop_interval = 2;
        command = args[1];
    }
    if (string_compare("dirty",command))
    {
        time_t before_seconds, after_seconds;
        before_seconds = time(NULL);
        while (1)
        {
            struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };
            char ch;

            if( poll(&mypoll, 1, 1))
            {
                scanf("%c",&ch);                                        // Need to run this without enter
                if (ch=='q')    break;
            }
            else
            {
                after_seconds = time(NULL);
                if (after_seconds - before_seconds >= loop_interval || firstattempt==1){
                    firstattempt = 0;
                    before_seconds = after_seconds;
                    path = "/proc/meminfo";
                    FILE *fptr;
                    fptr = fopen(path,"r");
                    if (fptr)
                    {
                        while (fscanf(fptr,"%s",buf) != EOF)
                        {
                            //printf("%s\n",buf);
                            if (string_compare(buf,"Dirty:"))   
                            {
                                fscanf(fptr,"%s",buf);
                                printf("%s kb\n",buf);
                            }
                        }
                        fclose(fptr);
                    }
                    else	perror("fopen");
                }
            }
        }
    }
    else if (string_compare("interrupt",command))
    {
    	int cpuno = 0;
    	char c[1024];
    	char **tokens = malloc(1000 * sizeof(char*)), *one;
        time_t before_seconds, after_seconds;
        before_seconds = time(NULL);
        path = "/proc/interrupts";
        FILE *fptr;
        fptr = fopen(path,"r");
        fscanf(fptr,"%[^\n]", c);
        one = strtok(c,COMMAND_DLMTR);
        while (one)
        {
        	tokens[cpuno] = one;
        	cpuno++;
        	one = strtok(NULL,COMMAND_DLMTR);
        }
        for (i=0;i<cpuno;i++)	printf("CPU%d\t",i);
        printf("\n");
    	fclose(fptr);
        while (1)
        {
            struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };
            char ch;

            if( poll(&mypoll, 1, 1))
            {
                scanf("%c",&ch);                                        // Need to run this without enter
                if (ch=='q')    break;
            }
            else
            {
                after_seconds = time(NULL);
                if (after_seconds - before_seconds >= loop_interval || firstattempt==1){
                    firstattempt = 0;
                    before_seconds = after_seconds; 
                    fptr = fopen(path,"r");                   
                    if (fptr)
                    {
                        while (fscanf(fptr,"%s",buf) != EOF)
                        {
                            //printf("%s\n",buf);
                            if (string_compare(buf,"1:"))   
                            {
                                for (i=0;i<cpuno;i++)
                                {
                                    fscanf(fptr,"%s",buf);
                                    printf("%s\t",buf);
                                }
                                printf("\n");
                            }
                        }
                        fclose(fptr);
                    }
                    else	perror("fopen");
                }
            }
        }
    }
    else	fprintf(stderr,"nightswatch needs to be exuted with dirty or interrupt\n");
    return 1;
}
