INCLUDE = libft.h

SRCS = ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c		\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strnstr.c		\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_striteri.c	\
		ft_substr.c		\
		ft_strjoin.c 	\
		ft_strtrim.c		\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c   \
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c

OBJS_DIR = objs/
OBJS	 = $(SRCS:.c=.o)
SRCS_OBJS = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wextra -Wall
ARCHIVE = ar
ARFLAGS = -rcs

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR): $(INCLUDE) Makefile
	@printf "\033[0;32mMaking libft.....\n\e[0m"
	@$(CC) $(CFLAGS) -c $(SRCS)
	@mkdir -p $@
	@mv *.o $@

$(NAME): $(SRCS)
	@$(ARCHIVE) $(ARFLAGS) $(NAME) $(SRCS_OBJS)
	@printf "\033[0;32mLibft library complete!\n\e[0m"


clean:
	@rm -rf $(OBJS_DIR)
	@printf "\033[0;31mLIBFT : Cleaning process done!\n\e[0m"

fclean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@printf "\033[0;31mLIBFT : File cleaning process done!\n\e[0m"

re: fclean all

.PHONY: clean fclean re all bonus