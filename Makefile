HEADERS = header.h  
OBJECTS = shell_loop.o print_home.o command_split_read.o command_execute.o execute_cd.o execute_rest.o execute_pinfo.o execute_echo.o code.o execute_pwd.o string_fun.o execute_nightswatch.o execute_ls.o redirections.o execute_setenv.o execute_unsetenv.o signal_handler.o execute_jobs.o execute_kjob.o pop_job.o execute_overkill.o execute_fg.o execute_bg.o

default: shell clean

%.o: %.c $(HEADERS)
	gcc -c $< -o $@

shell: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)

cleanwhole:
	-rm -f $(OBJECTS)
	-rm -f shell
