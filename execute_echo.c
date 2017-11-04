#include"header.h"
#include"variables.h"
int execute_echo(char **args,int flag){
    // Usage: echo [option(s)] [string(s)]
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

    int i = 1;
    char x = '$';
    while(args[i] != NULL){
        if(args[i][0] == x){
            char s[2000];
            strcpy(s, &args[i][1]);
            char *print = getenv(s);
            if(print)
                printf("%s ", print);
        }
        else{
            if(args[i][0] == '\"' || args[i][0] == '\''){
                for(int z = 1;z < strlen(args[i]); z++)
                    if(args[i][z] != '\'' && args[i][z] != '\"')
                        printf("%c", args[i][z]);
                printf(" ");
            }
            else if (args[i][strlen(args[i])-1] == '\"' || args[i][strlen(args[i])-1] == '\'' ){
                for(int z = 0;z < strlen(args[i])-1; z++)
                    if(args[i][z] != '\'' && args[i][z] != '\"')
                        printf("%c", args[i][z]);
                printf(" ");
            }
            else
                printf("%s ", args[i]);
        }
        i++;
    }
    printf("\n");

    file_in = fd[0];
    close(fd[1]);
    dup2(saved_stduot,1);
    return 1;
}
