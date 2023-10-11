FILES	=	Email/email.c\
			Password/Password.c\
			Print/Print.c\
			Inputs\inputs.c
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
