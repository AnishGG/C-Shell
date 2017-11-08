#include"header.h"
#include"variables.h"

int execute_unsetenv(char ** args, int flag)
{
    int i = 0;
    while (args[i])
    {
    	i++;
    }
    if (i==1 || i>2)	fprintf(stderr, "Invalid arguements: Needed exactly 1 arguement\n");
    else if (i==2)
    {
    	unsetenv(args[1]);
    }
    return 1;
}