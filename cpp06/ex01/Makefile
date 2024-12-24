NAME		=	serializer
SRCS		=	main.cpp Serializer.cpp
INC_DIR		=    .
CXX			=    c++
CXXFLAGS	=    -Wall -Wextra -Werror -std=c++98
RM			=    rm -f
OBJS		=    $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $(NAME)

fclean: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(OBJS)

re:    fclean all

.PHONY:    all clean fclean re
