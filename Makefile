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
LDFLAGS=-L$(MINILIBX_DIR) -L$(LIBFT_DIR)
LIBS=-lm -lft -lmlx

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -j4 -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -j4 -C $(MINILIBX_DIR)

.PHONY: clean fclean re

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
