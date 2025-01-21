SRC_PATH = src/
SRCS = main.c \
		parsing.c \
		free.c  \
		push.c  \
		swap.c  \
		rotate.c \
		reverse_rotate.c \
		utils.c \
		mini_swap.c \
		utils_another_one.c \
		quick_sort.c

SRCS_PREFIXED = $(addprefix $(SRC_PATH), $(SRCS))

INCLUDE = include/push_swap.h

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT_PATH = lib/libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

PRINTF_PATH = lib/ft_printf/

PRINTF_LIB = $(PRINTF_PATH)libftprintf.a

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: SUBSYSTEMS $(OBJS) $(NAME)

SUBSYSTEMS: 
	@make -C $(LIBFT_PATH) all -s
	@make -C $(PRINTF_PATH) all -s

$(OBJS_DIR)%.o: $(SRC_PATH)%.c Makefile $(INCLUDE)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32mCompiling: $<\e[0m\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)
	@printf "\033[0;32m$(NAME) compiled\n\e[0m"

clean:
	@make -C $(LIBFT_PATH) clean -s
	@make -C $(PRINTF_PATH) clean -s
	@rm -rf $(OBJS_DIR)
	@printf "\033[0;31mCleaning process done!\n\e[0m"

fclean:
	@make -C $(LIBFT_PATH) fclean -s
	@make -C $(PRINTF_PATH) fclean -s
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@printf "\033[0;31mFile cleaning process done!\n\e[0m"

re: fclean all

.PHONY: clean fclean re all bonus
