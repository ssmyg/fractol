/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/06 16:32:24 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define KEY_0 29
# define KEY_Z 6
# define KEY_X 7
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define MOUSE_LEFT 1

# define SCROLL_UP 4
# define SCROLL_DOWN 5

//# define WINDOW_W 700
//# define WINDOW_H 500
// # define WINDOW_W 1920
// # define WINDOW_H 1080
# define WINDOW_W 1000
# define WINDOW_H 1000
# define MAX_LOOP 50
# define MAX_Z 10.0

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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	double	scale;
	int		dx;
	int		dy;

	int		is_down;
	int		down_x;
	int		down_y;
}			t_vars;

int			trgb(int t, int r, int g, int b);
int			hsv2rgb(int h, int s, int v);
void		drow_mandelbrot(t_vars *vars);

#endif
