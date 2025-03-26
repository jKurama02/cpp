NAME = ex01
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp Data.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@rm -f $(OBJ)

fclean: clean
				@rm -f $(NAME)

re: fclean all
