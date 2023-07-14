NAME=fractol
CFLAGS=-Wall -Wextra -Werror -O3
SRC_DIR=.
SRCS=src/main.c src/color.c src/keyboard.c src/mouse.c src/window.c src/render.c \
	src/mandelbrot.c src/julia.c src/sierpinski.c src/arg.c src/model.c src/message.c
OBJS=$(SRCS:.c=.o)
LIBFT_DIR=./libft
LIBFT=$(LIBFT_DIR)/libft.a
MINILIBX_DIR=./minilibx_opengl_20191021
MINILIBX=$(MINILIBX_DIR)/libmlx.a
INCLUDES=-I./includes/ -I$(MINILIBX_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	$(CC) $(OBJS) -L$(MINILIBX_DIR) -L$(LIBFT_DIR) -lm -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

.PHONY: clean fclean re

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
