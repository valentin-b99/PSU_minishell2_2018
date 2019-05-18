##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	= src/*.c

OBJ	= $(SRCS:.c=.o)

LIBFLAG	= -L ./lib/my/ -lmy

all: $(NAME)

$(NAME):
	cd lib/my && make re
	$(CC) $(SRCS) -o $(NAME) $(LIBFLAG) -g3

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) ./lib/my/libmy.a

re: fclean all

.PHONY: all clean fclean re