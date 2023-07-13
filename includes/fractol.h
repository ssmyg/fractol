/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 16:14:47 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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

	int					win_w;
	int					win_h;

	int					color;
	int					(*model)(int, int, t_vars *);
	long double			c[2];
};

int						trgb(int t, int r, int g, int b);
int						hsv2rgb(int h, int s, int v);

void					drow_img(t_vars *vars);
int						render_frame(t_vars *vars);

int						set_arg(int argc, char *argv[], t_vars *vars);

#endif
