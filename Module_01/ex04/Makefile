CC      		= 	c++
CFLAGS  		= 	-Wall -Werror -Wextra -std=c++98
CFLAGS_DEBUG 	=	-fsanitize=address,undefined

SRC     		=	main.cpp \
					StringReplacer.cpp
OBJ 		    = 	$(SRC:%.cpp=%.o)
NAME		    = 	sedIs4L0S3rS

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🏗  Building a" $@ "👌"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo "🧹Cleaning up... ✌️"
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "🧽🧼 Full cleaning... ✨"
	@/bin/rm -f $(NAME)


debug: 	CFLAGS += $(CFLAGS_DEBUG)
debug:	all

lldb_g: CFLAGS += -g
lldb_g: all

re: 	fclean all

.PHONY: all clean fclean debug lldb re
