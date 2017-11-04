#include"header.h"
#include"variables.h"



int command_execute(char **args, int flag){
    int i = 0, status;
    if(!args[i]){
        return 1;
    }
    else{
        for(i = 0;i < num_of_internal(); i++){
            if(string_compare(args[0], internal_commands[i])){
                if(string_compare(internal_commands[i], "cd")){
                    status = execute_cd(args,flag);
                    return status;
                }
                else if(string_compare(internal_commands[i], "echo")){
                    status = execute_echo(args,flag);
                    return status;
                }
                else if(string_compare(internal_commands[i], "pwd")){
                    status = execute_pwd(flag);
                    return status;
                }
                else if(string_compare(internal_commands[i], "ls")){
                    status = execute_ls(args,flag);
                    return status;
                }
                else if(string_compare(internal_commands[i], "exit")){
                    status = execute_exit();
                    return status;
                }
                else if(string_compare(internal_commands[i], "pinfo")){
                    status = execute_pinfo(args,flag);
                    return status;
                }
                else if (string_compare(internal_commands[i], "nightswatch")){
                    status = execute_nightswatch(args,flag);
                    return status;
                }
                else{
                    printf("Command not found\n");
                    return 1;
                }
            }
        }
        return execute_rest(args,flag);
    }
}
