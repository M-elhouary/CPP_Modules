<<<<<<< HEAD
NAME = identify
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
=======

# Name of the executable
NAME = megaphone
		
# Compiler and flags
CXX = c++
# Compiler flags
CXXFLAGS = -Wextra -Werror -Wall -std=c++98

# Source files
SRCS = megaphone.cpp

# Object files
OBJ = $(SRCS:.cpp=.o)

# first target: build the executable
all: $(NAME)

# Rule for compiling .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for compiling source files into object files
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# remove object files
clean:
	rm -f $(OBJ)

# remove executable and object files
fclean: clean
	rm -f $(NAME) $(OBJ)

# Rebuild the project
re: fclean all

# non-file commands
.PHONY: all clean fclean re
>>>>>>> 82b0676e7b45d3dfd0f154efa2316bbc5dde1bf3
