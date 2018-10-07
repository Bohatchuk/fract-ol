NAME = fractol

CC = gcc

FLAGS = -Wall -Wextra -Werror

FRAM = -lmlx -framework OpenGL -framework AppKit

SRCS =	fractal_calc.c \
		fractal_init.c \
		functions.c \
		hooks.c \
		main.c \
		pthread_burningship.c \
		pthread_julia.c \
		pthread_mandelbrot.c \
		tools.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft/

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(FLAGS) $(FRAM) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "\033[1;35mCompilation of Fractol:	DONE.\033[m"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@rm -rf $(OBJS)
	@echo "\033[1;35mRemoving Fractol Objs:	DONE.\033[m"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[1;35mRemoving Fractol Executable:	DONE.\033[m"

re: fclean all

.PHONY: all clean fclean re