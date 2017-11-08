#include"header.h"
#include"variables.h"

int command_execute(char **args, int flag){
    int i = 0, status;
    if(!args[i]){
        return 1;
    }
    else{
        for(i = 0;i < num_of_internal(); i++){
            if(string_compare(args[0], internal_commands[i]))
            {
/* This section is for piping */
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
/*Section ends here */
                if(string_compare(internal_commands[i], "cd")){
                    status = execute_cd(args,flag);
                }
                else if(string_compare(internal_commands[i], "bg")){
                    status = execute_bg(args);
                }
                else if(string_compare(internal_commands[i], "fg")){
                    status = execute_fg(args);
                }
                else if(string_compare(internal_commands[i], "jobs")){
                    status = execute_jobs(flag);
                }
                else if(string_compare(internal_commands[i], "overkill")){
                    status = execute_overkill(flag);
                }
                else if(string_compare(internal_commands[i], "kjob")){
                    status = execute_kjob(args,flag);
                }
                else if(string_compare(internal_commands[i], "echo")){
                    status = execute_echo(args,flag);
                }
                else if(string_compare(internal_commands[i], "pwd")){
                    status = execute_pwd(flag);
                }
                else if(string_compare(internal_commands[i], "ls")){
                    status = execute_ls(args,flag);
                }
                else if(string_compare(internal_commands[i], "quit")){
                    status = execute_exit();
                }
                else if(string_compare(internal_commands[i], "pinfo")){
                    status = execute_pinfo(args,flag);
                }
                else if (string_compare(internal_commands[i], "nightswatch")){
                    status = execute_nightswatch(args,flag);
                }
                else if (string_compare(internal_commands[i],"setenv"))
                {
                    status = execute_setenv(args, flag);
                }
                else if (string_compare(internal_commands[i],"unsetenv"))
                {
                    status = execute_unsetenv(args,flag);
                }
                else{
                    printf("Command not found\n");
                    return 1;
                }
                /*For piping*/
                file_in = fd[0];
                close(fd[1]);
                dup2(saved_stduot,1);
                /*Section End*/
                return status;
            }
        }
        return execute_rest(args,flag);
    }
}
