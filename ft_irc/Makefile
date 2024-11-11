NAME		=	irc
SRCDIR		=	srcs
INC_DIR		=	-I includes/All.h
OBJDIR		=	objs
SRCS		=	$(wildcard $(SRCDIR)/*.cpp)
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f
OBJS		=	$(SRCS:$(SRCDIR)%.c=$(OBJDIR)/%.o)

all:	$(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)%.cpp | $(OBJDIR)
	$(CC) $(CCFLAGS) $(INC_DIR)  -o $@ -c $<

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re