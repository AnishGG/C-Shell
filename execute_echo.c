#include"header.h"
#include"variables.h"
int execute_echo(char **args,int flag){
    // Usage: echo [option(s)] [string(s)]
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
    return 1;
}
