NAME = rpn

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = RPN.cpp main.cpp

OBG = $(SRC:.cpp=.o)

$(NAME): $(OBG)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBG)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re