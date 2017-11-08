#include"header.h"
#ifndef prt
#define prt
extern char OLDPWD[2000] , HOME[2000];
extern char *internal_commands[];
extern int file_in;
extern int file_out;
extern int background_jobs;
extern int shell_setpgid;
typedef struct jobs{
    char status[10], name[101];
    pid_t pid;
    int flag;   // Keeps  check whether job is running or stopped
    // flag = 1 means process is running
}jobs;
extern jobs job[1010];
extern jobs child_pid;
#endif
