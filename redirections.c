#include"header.h"
#include"variables.h"

void input_redirection(char * line)
{
	int i = 0;
    char newline[1000];
    for (i=0;i<strlen(line);i++)
        newline[i] = line[i];
    newline[i] = '\0';
    char ** intemp = myparser(newline, "<");
    if (intemp[1]!= NULL)
    {
    	char ** temp = myparser(intemp[1], " ");
    	file_in = open(temp[0], O_RDONLY);
    }
}

void output_redirection(char * line, int flag)
{
	int i = 0;
    char newline[1000];
    for (i=0;i<strlen(line);i++)
        newline[i] = line[i];
    newline[i] = '\0';
    char ** intemp = myparser(newline, ">");

    if (intemp[1]!= NULL)
    {
    	char ** temp = myparser(intemp[1]," ");
    	if (flag == 0) file_out = open(temp[0],O_TRUNC | O_WRONLY | O_CREAT, S_IRWXU);
        else    
        {
            file_out = open(temp[0], O_WRONLY | O_CREAT, S_IRWXU); 
            lseek(file_out, 0,SEEK_END);
        }
    }
    else
    	file_out = 1;
}
