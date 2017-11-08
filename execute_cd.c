#include"header.h"
#include"variables.h"
int execute_cd(char **args,int flag){
    char pwd[2000];getcwd(pwd, sizeof(pwd));
    if(args[1] == NULL){
        char *s = HOME;
        int stat = chdir(s);
        if(stat != 0)
            perror("shell");
        else{
            strcpy(OLDPWD, pwd);
        }
    }
    else if(string_compare(args[1], "-")){
        if(string_compare(OLDPWD, "\0")){
            fprintf(stderr, "shell: cd: OLDPWD not set\n");
        }   
        else{
            int stat = chdir(OLDPWD);
            if(stat != 0)
                perror("shell");
            else{
                printf("%s\n", OLDPWD);
                strcpy(OLDPWD, pwd);
            }
        }
    }
    else if(args[1][0] == '~'){
        int stat = chdir(concat(HOME, &args[1][1]));
        if(stat != 0)   perror("shell");
        else            strcpy(OLDPWD, pwd);
    }
    else{
        int stat = chdir(args[1]);
        if(stat != 0)
            perror("shell");    // Here I 'll place the name of my shell
        else{
            strcpy(OLDPWD, pwd);
        }
    }
    return 1;
}
