/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 11:50:41 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// keyboard
# define KEY_0 29
# define KEY_C 8
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

// mouse
# define MOUSE_LEFT 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define WINDOW_W 700
# define WINDOW_H 500
//# define WINDOW_W 1980
//# define WINDOW_H 1080

# define INIT_LOOP 25
# define MAX_Z 6.0
# define ZOOM_RATE 1.25

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_vars	t_vars;

struct					s_vars
{
	void				*mlx;
	void				*win;

	long double			scale;
	long double			dx;
	long double			dy;

	int					is_down;
	long double			down_x;
	long double			down_y;

	t_data				img;

	int					progress;
	int					loop;

	int					win_w;
	int					win_h;

	int					color;
	int					(*model)(int, int, t_vars *);
};

int						trgb(int t, int r, int g, int b);
int						hsv2rgb(int h, int s, int v);
void					drow_mandelbrot(t_vars *vars);

int						mouse_move(int x, int y, t_vars *vars);
int						mouse_down(int key, int x, int y, t_vars *vars);
int						mouse_up(int key, int x, int y, t_vars *vars);

int						key_hook(int keycode, t_vars *vars);

void					drow_img(t_vars *vars);

int						render_frame(t_vars *vars);

void					init_vars(t_vars *vars);
void					init_window(t_vars *vars);
void					set_hooks(t_vars *vars);
int						window_close(t_vars *vars);

void					to_z(int w, int h, double z[], t_vars *vars);

int						mandelbrot(int w, int h, t_vars *vars);
int						julia(int w, int h, t_vars *vars);
int						sierpinski(int w, int h, t_vars *vars);

int						set_arg(int argc, char *argv[], t_vars *vars);

#endif
