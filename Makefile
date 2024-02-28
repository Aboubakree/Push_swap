NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC = main.c push_swap_1.c push_swap_2.c push_swap_3.c\
	push_swap_4.c\
	libft/ft_split_v2.c libft/ft_atoi.c libft/ft_lstsize.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all