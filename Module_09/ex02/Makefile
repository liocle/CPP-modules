CC          = c++
CFLAGS      = -Wall -Werror -Wextra -std=c++11 -Wpedantic
DEBUG_FLAGS = -fsanitize=address -fsanitize=undefined -g

SRC         = main.cpp \
			  PmergeMe.cpp 
OBJ         = $(SRC:.cpp=.o)
NAME        = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building $@"
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning..."
	rm -f $(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

lldb_g: CFLAGS += -g
lldb_g: re

re: fclean all

.PHONY: all clean fclean debug lldb_g re

