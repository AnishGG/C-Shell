#include"header.h"
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
//    in real code you would check for errors in malloc here
        strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int string_compare(char *a, char *b){
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0' && a[i] != '\n' && b[i] != '\n'){
        if(a[i] != b[i])
            return 0;
        else if(a[i] == b[i])
            i++;
    }   
    if(a[i] != b[i])
        return 0;
    else
        return 1;
}

