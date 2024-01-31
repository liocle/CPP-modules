CC      		= 	c++
CFLAGS  		= 	-Wall -Werror -Wextra -std=c++11
CFLAGS_DEBUG 	=	-fsanitize=address,undefined

SRC     		=	main.cpp \
					Bureaucrat.cpp \
					AForm.cpp \
					PresidentialPardonForm.cpp \
					RobotomyRequestForm.cpp \
					ShrubberyCreationForm.cpp \
					


OBJ 		    = 	$(SRC:%.cpp=%.o)

NAME		    = 	bureaucrat
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building "  $@ 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo "Cleaning up..."
	/bin/rm -f $(OBJ) *_shrubbery

fclean: clean
	@echo "Full cleaning..."
	/bin/rm -f $(NAME)


debug: 	CFLAGS +=$(CFLAGS_DEBUG)
debug:	all

lldb_g: CFLAGS += -g
lldb_g: all

re: 	fclean all

.PHONY: all clean fclean debug lldb re
