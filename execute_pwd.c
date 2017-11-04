#include"header.h"
#include"variables.h"
int execute_pwd(int flag){
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

    char pwd[2000];
    getcwd(pwd,sizeof(pwd));
    printf("%s\n", pwd);

    file_in = fd[0];
    close(fd[1]);
    dup2(saved_stduot,1);
    return 1;
}

