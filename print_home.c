#include"header.h"
#include"variables.h"
void printhome()
{
    char pwd[2000], host_name[2000], *username;
    gethostname(host_name,sizeof(host_name));
    username = (char *)malloc(200*sizeof(char));
    cuserid(username);
    getcwd(pwd,sizeof(pwd));
    printf(KGRN "%s@%s:" RESET,username,host_name);
    int i=0, count = 0;
    i = 0;
    char *home = HOME;char pwd2[2000];
    count = strlen(home);home[count] = '\0';   // This had to be written as \0 was not present at last.
    strcpy(pwd2, pwd);pwd2[count] = '\0';
    if(string_compare(pwd2, home)){
        if(strlen(home) == strlen(pwd)){
            printf(KBLU "[~]> " RESET);
        }
        else{
            printf(KBLU "[~/");
            while (pwd[i])
            {
                if (i > count)                  
                    printf("%c",pwd[i]);
                i++;
            }
            printf("]> " RESET);
        }
    }
    else{
        printf(KBLU "[");
        printf("%s", pwd);
        printf("]> "RESET);
    }
}
