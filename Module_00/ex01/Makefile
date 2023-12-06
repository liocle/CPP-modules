CC      		= 	c++
CFLAGS  		= 	-Wall -Werror -Wextra -std=c++98
CFLAGS_DEBUG 	=	-fsanitize=address,undefined

SRC     		=	main.cpp \
					Contact.cpp \
					PhoneBook.cpp \
					BoxDrawing.cpp \
					Display.cpp
OBJ 		    = 	$(SRC:%.cpp=%.o)
NAME		    = 	phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean debug lldb re

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)


debug: 	CFLAGS + =$(CFLAGS_DEBUG)
debug:	all

lldb_g: CFLAGS += -g
lldb_g: all

re: 	fclean all

