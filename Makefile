NAME=fractol
CFLAGS=-Wall -Wextra -Werror
SRC_DIR=.
SRCS=src/main.c src/color.c
OBJS=$(SRCS:.c=.o)
MINILIBX_DIR=./minilibx_opengl_20191021/
MINILIBX=$(MINILIBX_DIR)/libmlx.a
INCLUDES=-I./includes/ -I$(MINILIBX_DIR)

all: $(NAME)

#$(NAME): $(OBJS)
#	$(CC) -o $(NAME) $(OBJS)

$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $(OBJS) -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


#$(OBJS):
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
#	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

.PHONY: clean fclean re

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all
