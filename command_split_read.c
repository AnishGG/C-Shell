#include"header.h"
/* Spliting a command in accordance with predefined delimiters */
char **command_spliter(char *command){
    int pos = 0;
    char **tokens = malloc(1000 * sizeof(char*)), *one;
    if(!tokens){
        fprintf(stderr, "Error in allocating space\n");
        exit(EXIT_FAILURE);
    }
    one = strtok(command, COMMAND_DLMTR);
    while(one){
        //        printf("%s\n", one);
        tokens[pos] = one;
        pos++;
        one = strtok(NULL, COMMAND_DLMTR);
    }
    tokens[pos] = NULL;
    return tokens;
}

/* Spliting a command in accordance with a particular delimiter */
char** myparser(char *command, char* delimiter)
{
    int pos = 0;
    char ** mytoken = malloc(1000*sizeof(char *)), *one;
    if (!mytoken)
    {
        fprintf(stderr, "Error in allocating space\n");
        exit(EXIT_FAILURE);
    }
    one = strtok(command, delimiter);
    while(one)
    {      
        mytoken[pos] = one;
        pos++;
        one = strtok(NULL, delimiter); 
    }
    mytoken[pos]='\0';
    pos++;
    return mytoken;
}

/* This function returns commands seperated by semi-colon */
char **command_reader(){
    int line_size = 1000, pos = 0, c;
    char *line = malloc(sizeof(char) * line_size);
    if(!line){
        fprintf(stderr, "Error in allocating space\n");
        exit(EXIT_FAILURE);
    }
    while(1){
        // all the characters will be stored in their integer format, giving comfort in breaking them.
        c = getchar();  // This function waits for input
        if(c == '\n'){
            line[pos] = '\0';
            break;
        }
        else{
            line[pos++] = c;
        }
    }
    pos = 0;
    // breaking the commands after ";"
    /*printf("%s\n", line);*/
    char **commands = malloc(1000 * sizeof(char*)), *command;
    if(!commands){
        fprintf(stderr, "Error in allocating space\n");
        exit(EXIT_FAILURE);
    }
    command = strtok(line, ";");
    while(command){
        commands[pos] = command;
        //        printf("%s\n", command);
        pos++;
        command = strtok(NULL, ";");
    }
    commands[pos] = NULL;
    return commands;
}
