# Bash Shell:

### Usage:
1. make
2. ./shell

### Files:
	* code.c 	            -	contains the main file
	* command_split_read.c 	-	helps in parsing the commands
	* execute_echo.c 	    -	Function to execute echo
	* execute_nightswatch.c 	- 	Function to execute nightswatch
	* execute_pwd.c 	    -	Function to get the current working directory
	* print_home.c 	        -	helps in printing the prompt
	* shell_loop.c 	        -	To continue the prompt after every command
	* command_execute.c 	- 	Executing a given command
	* execute_cd.c 	        -	Function to execute cd
	* execute_pinfo.c 	    -	Function to execute pinfo
	* execute_rest.c 	    -	Function to execute commands not in the built in commands
	* string_fun.c 	        -	helps in string operations

### Commands that can be run on the shell:
	* pwd	                -	Get the present working directory
	* cd                    -	Change directory
	* ls with options -l and -a  -	List the contents(files/folders/symlinks, etc)
	* echo
	* pinfo             	-	Get the process information
	* pinfo <pid>	        -	Get the process information of the given process id
	* quit	                -	Exit the shell
	* clear	                -	Clear the screen
	* nightswatch <dirty/interrupt>	with option -n 	-	print the dirty memory/ cpu interrupts from keyboard controller every n seconds (default 2)
	* background processes can be run with &	    -	Get processes running in the background
