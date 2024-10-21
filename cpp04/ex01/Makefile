NAME		=	a.out
SRCS		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
INC_DIR        =    .
CC            =    g++
CFLAGS        =    -Wall -Wextra -Werror -std=c++98
DBUG = -fsanitize=address -fno-omit-frame-pointer -g
RM            =    rm -f
OBJS        =    $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)

debug: $(OBJS)
	@$(CC) $(DBUG) $(CFLAGS) $^ -o $(NAME)


fclean: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(OBJS)

re:    fclean all

.PHONY:    all clean fclean re