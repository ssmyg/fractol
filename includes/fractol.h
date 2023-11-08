/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/11/08 15:28:10 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 720
# define WINDOW_HEIGHT 480

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
	int					keycode;

	t_data				img;

	int					progress;
	int					loop;

	int					color;
	int					(*model)(int, int, t_vars *);
	int					is_julia;
	long double			c[2];
	long double			z[WINDOW_WIDTH * WINDOW_HEIGHT * 2];
	int					count[WINDOW_WIDTH * WINDOW_HEIGHT];
};

#endif
