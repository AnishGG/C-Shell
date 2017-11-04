#include"header.h"
#include"variables.h"
void shell_loop(void){
    int pipeflag = 0;
    char **commands, **args;
    int status = 1;
    do{
        printhome();
        commands = command_reader();
        int i = 0;
        while(commands[i] != NULL)
        {
            char ** pipecommand;
            pipecommand = myparser(commands[i],"|");
            int j = 0;
            while (pipecommand[j] != NULL)
            {                
                input_redirection(pipecommand[j]);
                output_redirection(pipecommand[j]);
                char **temp1;
                char **actual_command;
                temp1 = myparser(pipecommand[j], "<");
                actual_command = myparser(temp1[0], ">");
                args = command_spliter(actual_command[0]);
                if (pipecommand[j+1]!=NULL)
                    pipeflag = 1;
                else    pipeflag = 0;
                status = command_execute(args,pipeflag);
                j++;
                free(args);
            }
            file_in = 0;
            file_out = 1;
            i++;
            free(pipecommand);
        }
    }
    while(status);
}
