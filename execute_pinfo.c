#include"header.h"
#include"variables.h"
int execute_pinfo(char **args,int flag){
    int id=0, nextline = 0, i=0, valid = 0;
    char * procid;
    while (args[i])
    {
        if (i==1) procid = args[i];  
        i++;
    }
    if (i==1)  
        id = getpid();
    else if (i>2)
    {
        fprintf(stderr, "%s: command needs only 1 arguement\n", args[0]);
        return 1;
    }
    else
    {
        i=0;
        while (procid[i])
        {
            id = id * 10 + (procid[i]-'0');
            i++;
        }
    
        struct dirent * dir;
        DIR *d = opendir("/proc");
        while ((dir = readdir(d)) != NULL)
        {
            if (string_compare(dir -> d_name,procid) == 1)    
                valid = 1;
        }
        if (!valid)
        {
            fprintf(stderr,"%s: is not an existing process id\n",procid);
            return 1;
        }
    }
    printf("pid\t--\t%d\n",id);
    printf("Executable Path\t--\t");
    char buf[1024], *s,my_concat[1024];
    //concatenating string and integer
    sprintf(my_concat,"%s%d","/proc/",id);
	s = concat(my_concat, "/exe");
    ssize_t ret = readlink(s, buf, 1024);
    if (ret > 0)
    {   
        buf[ret] = '\0';
        printf("%s\n", buf);            // Might need formatting (~ symbol) 
    }   
    else    perror("readlink");
    s = concat(my_concat,"/status");
    FILE *fptr;
    fptr = fopen(s,"r");
    if (fptr)
    {
        while (fscanf(fptr,"%s",buf) != EOF)
        {
            //printf("%s\n",buf);
            if (nextline)   
            {
                printf("%s ",buf);
                fscanf(fptr,"%s",buf);
                printf("%s\n",buf);
                nextline = 0;
            }
            if (string_compare(buf,"State:"))   
            {
                printf("Process Status\t--\t");
                nextline = 1;
            }
            if (string_compare(buf,"VmSize:"))
            {
                printf("Virtual Memory\t--\t");
                nextline = 1;
            }
        }
    }
    fclose(fptr);
    return 1;
}
