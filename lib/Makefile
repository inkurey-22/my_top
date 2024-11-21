##
## EPITECH PROJECT, 2024
## my_libc
## File description:
## Makefile
##

SRC 	=   io/my_putnbr.c                   \
            io/my_putchar.c                  \
            io/my_putstr.c                   \
            io/my_puterr.c                   \
            io/my_show_word_array.c          \
            my_printf/my_printf.c            \
            my_printf/my_sprintf.c           \
            my_printf/my_dprintf.c           \
            my_printf/manage_spec.c          \
            my_printf/parse_flags.c          \
            my_printf/printf_g_spec.c        \
            my_printf/printf_n_spec.c        \
            my_printf/printf_putbase.c       \
            my_printf/printf_putchar.c       \
            my_printf/printf_putfloat.c      \
            my_printf/printf_putnbr.c        \
            my_printf/printf_putstr.c        \
            my_printf/printf_scientific.c    \
            my_printf/printf_tab.c           \
            my_printf/put_buffer.c           \
            my_printf/utilities.c            \
            my_printf/utilities2.c           \
            my_printf/utilities3.c           \
            my_printf/utilities4.c           \
            numbers/my_compute_power_rec.c   \
            numbers/my_compute_square_root.c \
            numbers/my_find_prime_sup.c      \
            numbers/my_getnbr.c              \
            numbers/my_isneg.c               \
            numbers/my_is_prime.c            \
            strings/my_revstr.c              \
            strings/my_str_isalpha.c         \
            strings/my_str_islower.c         \
            strings/my_str_isnum.c           \
            strings/my_str_isprintable.c     \
            strings/my_str_isupper.c         \
            strings/my_strcapitalize.c       \
            strings/my_strcat.c              \
            strings/my_strcmp.c              \
            strings/my_strcpy.c              \
            strings/my_strdup.c              \
            strings/my_strlen.c              \
            strings/my_strlowcase.c          \
            strings/my_strncat.c             \
            strings/my_strncmp.c             \
            strings/my_strncpy.c             \
            strings/my_strstr.c              \
            strings/my_strupcase.c           \
            strings/split_string.c           \
            lists/add_to_top.c               \
            lists/append.c                   \
            lists/create.c                   \
            lists/find.c                     \
            lists/free_list.c                \
            lists/remove.c                   \
            lists/reverse.c                  \
            lists/size.c                     \
            lists/sort.c

CC 	    =   gcc

AR 	    =   ar rc

NAME    =   libmy.a

OBJ_DIR =   obj

OBJ     =   $(SRC:%.c=$(OBJ_DIR)/%.o)

CFLAGS  =   -I../include -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@cp io/my_io.h ../include
	@cp my_printf/my_printf.h ../include
	@cp numbers/my_numbers.h ../include
	@cp strings/my_strings.h ../include
	@cp lists/my_lists.h ../include

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
