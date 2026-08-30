NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -I includes
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
