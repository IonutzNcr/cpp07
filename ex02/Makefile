NAME = a.out
FLAGS = -Wall -Wextra -Werror -std=c++98
FILES = main.cpp
OBJ = $(FILES:.cpp=.o)
HEADER = Array.hpp

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADER)
	@echo "Compiling $<"
	c++ $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re%% comp