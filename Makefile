##
## EPITECH PROJECT, 2024
## base_repo
## File description:
## Makefile
##

SRC    =    src/main.c		\
			src/loadavg.c	\
			src/header.c	\
			src/time.c

NAME   =    my_top

CC     =    gcc

CFLAGS =    -W -Wall -Wextra -Iinclude -Llib -lmy -lncurses -g

OBJ    =    $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib

re:	fclean all
