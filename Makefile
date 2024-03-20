NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c push_swap_1.c push_swap_2.c push_swap_3.c\
	push_swap_4.c push_swap_5.c push_swap_6.c push_swap_7.c\
	push_swap_8.c push_swap_9.c push_swap_10.c push_swap_11.c\
	libft/ft_split.c libft/ft_atoi.c libft/ft_lstsize.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all