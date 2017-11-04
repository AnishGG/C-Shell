#include"header.h"
#include"variables.h"

void input_redirection(char * line)
{
	int i = 0;
    char newline[1000];
    for (i=0;i<strlen(line);i++)
        newline[i] = line[i];
    char ** intemp = myparser(newline, "<");
    if (intemp[1]!= NULL)
    {
//    	char * innertemp = malloc(sizeof(char) * 1000);
    	char ** temp = myparser(intemp[1], " ");
    	file_in = open(temp[0], O_RDONLY);
    }
}

void output_redirection(char * line)
{
	int i = 0;
    char newline[1000];
    for (i=0;i<strlen(line);i++)
        newline[i] = line[i];
    char ** intemp = myparser(newline, ">");
    if (intemp[1]!= NULL)
    {
    	char ** temp = myparser(intemp[1]," ");
    	file_out = open(temp[0],O_TRUNC | O_WRONLY | O_CREAT, S_IRWXU);
    }
    else
    	file_out = 1;
}
