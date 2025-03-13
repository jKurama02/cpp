NAME = ex00
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp animal.cpp dog.cpp cat.cpp WrongAnimal.cpp WrongCat.cpp
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
