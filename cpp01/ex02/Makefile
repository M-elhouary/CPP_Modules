NAME = brain

CXX = c++

CXXFLAGS = -Wextra  -Wextra -Wall -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp

	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

clean : 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re