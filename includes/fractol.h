/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/11 11:45:41 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// keyboard
# define KEY_0 29
# define KEY_Z 6
# define KEY_X 7
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

# define INIT_LOOP 25

# define MAX_Z 10.0

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
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;

	long double	scale;
	long double	dx;
	long double	dy;

	int			is_down;
	long double	down_x;
	long double	down_y;

	t_data		img;

	int			progress;
	int			loop;

	int			win_w;
	int			win_h;
}				t_vars;

int				trgb(int t, int r, int g, int b);
int				hsv2rgb(int h, int s, int v);
void			drow_mandelbrot(t_vars *vars);

#endif
