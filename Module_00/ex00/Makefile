CC      = c++
CFLAGS  = -Wall -Werror -Wextra -std=c++98
SRC     = megaphone.cpp
OBJ     = $(SRC:%.cpp=%.o)
NAME    = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

