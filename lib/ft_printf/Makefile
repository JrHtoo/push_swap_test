SRCS = ft_nbrtohex.c	\
		ft_printf_format.c	\
		ft_printf_utils.c	\
		ft_printf.c		\
		ft_putnbr.c		\
		ft_putptr.c		\
		ft_putunbr.c

INCLUDE = ft_printf.h

OBJS_DIR = objs/
OBJS	 = $(SRCS:.c=.o)
SRCS_OBJS = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = libftprintf.a

CC = gcc
CFLAGS = -Werror -Wextra -Wall
ARCHIVE = ar
ARFLAGS = -rcs

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR): $(INCLUDE) Makefile
	@$(CC) $(CFLAGS) -c $(SRCS)
	@mkdir -p $@
	@mv *.o $@

$(NAME): $(SRCS)
	@printf "\033[0;32mMaking libftprintf.....\n\e[0m"
	@$(ARCHIVE) $(ARFLAGS) $(NAME) $(SRCS_OBJS)
	@printf "\033[0;32mLibftprintf library complete!\n\e[0m"


clean:
	@rm -rf $(OBJS_DIR)
	@printf "\033[0;31mLIBFTPRINTF : Cleaning process done!\n\e[0m"

fclean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@printf "\033[0;31mLIBFTPRINTF : File cleaning process done!\n\e[0m"

re: fclean all

.PHONY: clean fclean re all