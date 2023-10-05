FILES	=	Password_Generator/Password_Generator.c
FLAGS	=	-Wall -Werror -Wextra
VISIBILITY	=	@
NAME	= Account-Manager
run:
	$(VISIBILITY)cc $(FLAGS) main.c $(FILES) -o $(NAME)
debug:
	$(VISIBILITY)cc -g $(FLAGS) main.c $(FILES) -o $(NAME)
clean:
	$(VISIBILITY)rm $(NAME) 
valgrind:	debug
	$(VISIBILITY)valgrind --tool=memcheck ./$(NAME)
