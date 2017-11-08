#include"header.h"
#include"variables.h"
int execute_pwd(int flag){
    char pwd[2000];
    getcwd(pwd,sizeof(pwd));
    printf("%s\n", pwd);
    return 1;
}

