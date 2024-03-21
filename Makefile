NAME = push_swap
NAME2 = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c push_swap_1.c push_swap_2.c push_swap_3.c\
	push_swap_4.c push_swap_5.c push_swap_6.c push_swap_7.c\
	push_swap_8.c push_swap_9.c push_swap_10.c push_swap_11.c\
	push_swap_12.c\
	libft/ft_split.c libft/ft_atoi.c libft/ft_lstsize.c\
	

SRC_BONUS = push_swap_bonus.c push_swap_1.c push_swap_2.c push_swap_6.c push_swap_bonus_1.c push_swap_bonus_2.c\
	push_swap_bonus_3.c\
	libft/ft_split.c libft/ft_atoi.c libft/ft_lstsize.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus : $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ_BONUS)

clean: 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all