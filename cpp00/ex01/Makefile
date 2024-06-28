NAME		=	megaphone
SRCS		=	megaphone.cpp
CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f
OBJS		=	$(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)

fclean: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(OBJS)

re:	fclean all

.PHONY:	all clean fclean re