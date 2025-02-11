NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = converting.c linkedlist.c push.c rotate.c helpers.c sorting.c swap.c \
		main.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_COMMIT = e99f0e6

all: $(LIBFT) $(NAME)

$(LIBFT):
	git clone https://github.com/put/libft.git $(LIBFT_DIR)
	cd $(LIBFT_DIR) && git checkout $(LIBFT_COMMIT)
	make -C $(LIBFT_DIR) all

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -rf $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re