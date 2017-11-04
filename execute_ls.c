#include"variables.h"
#include"header.h"

// This is constructed by changing directories as opendir() was not working on parent directories. Ask why?
int execute_ls(char **args,int flag){
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
    int num, one = 0, two = 0, i = 1, k = 0;
    char **direc = malloc(1000*(sizeof(char*)));
    while(args[i]){
        if(args[i][0] == '-'){
            for(int j = 1;j < strlen(args[i]); j++){
                if(args[i][j] == 'l')   one = 1;
                else if(args[i][j] == 'a')   two = 1;
                else{
                    fprintf(stderr, "invalid option -- '%c'\n", args[i][j]);
                    return 1;
                }
            }
        }
        else if(args[i][0] == '~'){
            direc[k++] = concat(HOME, &args[i][1]);
        }
        else{
            direc[k++] = args[i];   // saving directoris for ls
        }
        i++;
    }
    direc[k] = NULL;
    if(k == 0){direc[k] = "./";direc[++k] = NULL;}
    int cnt = k, n;
    if(one == 1 && two == 0)    num = 1;    // ls -l
    else if(one == 1 && two == 1) num = 2;  // ls -al
    else if(one == 0 && two == 0) num = 3;  // ls
    else if(one == 0 && two == 1) num = 4;  // ls -a

    char* month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct stat fileStat;
    struct tm *date_time;
    char timestr[20], pwd[2000];
    getcwd(pwd, sizeof(pwd));
    DIR * d;
    struct dirent *dir, **directories;
    k = 0;
    while(direc[k]){
        if(cnt > 1)
            printf("%s: \n", direc[k]);
        int check = chdir(direc[k]);
        n = scandir(".", &directories, NULL, alphasort);
        if(n < 0 || check != 0){
            perror("ls");
            k++;
            continue;
        }
        int i = 0;
        while(i < n){
            dir = directories[i];
            i++;
            if(stat(dir->d_name, &fileStat) < 0){
                fprintf(stderr, "Error in reading file\n");
                chdir(pwd);
                return 1;
            }
            else
            {
                if((num == 1 || num == 3) && (dir->d_name)[0] == '.')
                    continue;
                if(num == 1 || num == 2)
                {
                    if (S_ISDIR(fileStat.st_mode))  printf("d");
                    else    printf("-");
                    if (fileStat.st_mode & S_IRUSR) printf("r");
                    else    printf("-");
                    if (fileStat.st_mode & S_IWUSR) printf("w");
                    else    printf("-");
                    if (fileStat.st_mode & S_IXUSR) printf("x");
                    else    printf("-");
                    if (fileStat.st_mode & S_IRGRP) printf("r");
                    else    printf("-");
                    if (fileStat.st_mode & S_IWGRP) printf("w");
                    else    printf("-");
                    if (fileStat.st_mode & S_IXGRP) printf("x");
                    else    printf("-");
                    if (fileStat.st_mode & S_IROTH) printf("r");
                    else    printf("-");
                    if (fileStat.st_mode & S_IWOTH) printf("w");
                    else    printf("-");
                    if (fileStat.st_mode & S_IXOTH) printf("x");
                    else    printf("-");
                    printf("\t");
                    printf("%lu\t",fileStat.st_nlink);
                    struct passwd * user = getpwuid(fileStat.st_uid);
                    struct group * group = getgrgid(fileStat.st_gid);
                    if (user != 0)  printf("%s\t",user -> pw_name);
                    else printf("\t");
                    if (group != 0) printf("%s\t",group -> gr_name);
                    else printf("\t");
                    if (lstat(dir->d_name,&fileStat)==0 && S_ISLNK(fileStat.st_mode))
                        printf("%ld\t",fileStat.st_size);
                    else    printf("%ld\t",fileStat.st_size);
                    date_time = localtime(&fileStat.st_ctime);
                    printf("%s %d\t",month[date_time -> tm_mon],date_time -> tm_mday);
                    strftime(timestr, 100, "%H:%M\t", localtime(&fileStat.st_ctime));       // Need to check if access time ot modified time a_time,c_time,a_time
                    printf("%s",timestr);
                }
                if (S_ISDIR(fileStat.st_mode))  printf(KBLU "%s " RESET,dir -> d_name);
                else if (lstat(dir->d_name,&fileStat)==0 && S_ISLNK(fileStat.st_mode))      // Stat takes the file it refers to instead of the symbolic link
                {
                    printf(KCYN "%s" RESET,dir -> d_name);
                    if (one==1)
                    {
                        char buff[1024];
                        ssize_t len = readlink(dir -> d_name, buff, sizeof(buff)-1);
                        if (len != -1) 
                        {
                            buff[len] = '\0';
                            printf(" -> %s",buff);
                        }
                    }
                }
                else if (stat(dir -> d_name,&fileStat)==0 && ((fileStat.st_mode & S_IXUSR) || (fileStat.st_mode & S_IXGRP) || (fileStat.st_mode & S_IXOTH)))    printf(KGRN "%s" RESET,dir -> d_name);
                else    printf("%s ", dir->d_name);
            }
            printf("\n");
        }
        k++;
        if(cnt > 1)
            printf("\n");
    }
    chdir(pwd);
    file_in = fd[0];
    close(fd[1]);
    dup2(saved_stduot,1);
    return 1;
}
