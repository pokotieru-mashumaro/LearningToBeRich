NAME = minitalk
CFLAGS = -Wall -Wextra -Werror

$(NAME): server client

all: $(NAME)

server:
	cc $(CFLAGS) server.c -o server

client:
	cc $(CFLAGS) client.c -o client

clean:
	rm -f server client

fclean:	 clean

re:			fclean all

.PHONY: all clean fclean re