CC      		= 	c++
CFLAGS  		= 	-Wall -Werror -Wextra -std=c++11
CFLAGS_DEBUG 	=	-fsanitize=address,undefined

SRC     		=	main.cpp \
					AMateria.cpp \
					Character.cpp \
					Cure.cpp \
					Ice.cpp \
					MateriaSource.cpp 

OBJ 		    = 	$(SRC:%.cpp=%.o)

NAME		    = 	materia
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building "  $@ 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo "Cleaning up..."
	/bin/rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning..."
	/bin/rm -f $(NAME)


debug: 	CFLAGS +=$(CFLAGS_DEBUG)
debug:	all

lldb_g: CFLAGS += -g
lldb_g: all

re: 	fclean all

.PHONY: all clean fclean debug lldb re
