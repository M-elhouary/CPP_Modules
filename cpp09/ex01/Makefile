NAME = rpn

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = RPN.cpp main.cpp

OBG = $(SRC:.cpp=.o)

$(NAME): $(OBG)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBG)

all: $(NAME)

%.cpp%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re