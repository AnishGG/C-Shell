#ifndef guard
#define guard 

#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<grp.h>
#include<pwd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<sys/types.h>
#include<fcntl.h>
#include<poll.h>
#include<sys/utsname.h>
#include<sys/resource.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"
#define COMMAND_DLMTR " \n\t"       // includes space, nextLine, and tab

char* concat(const char *s1, const char *s2);
int string_compare(char *a, char *b);
int execute_pinfo(char **args, int flag);
int execute_nightswatch(char ** args, int flag);
void proc_exit(int mysig);
int execute_rest(char **args,int flag);
int execute_ls(char **args, int flag);
int execute_exit();
int execute_pwd(int flag);
char ** myparser();
void input_redirection(char * line);
void output_redirection(char * line, int flag);
int execute_cd(char **args,int flag);
int num_of_internal();
int command_execute(char **args,int flag);
char **command_spliter(char *command);
char **command_reader();
void printhome();
void shell_loop(void);
int execute_setenv(char ** args, int flag);
int execute_unsetenv(char ** args, int flag);
int execute_echo(char **args,int flag);
void signal_handler(int mysig);
void pop_job(int idx);
int execute_kjob(char **args, int flag);
int execute_jobs(int flag);
int execute_overkill(int flag);
int execute_fg(char **args);
int execute_bg(char **args);
void proc_killed();
#endif
