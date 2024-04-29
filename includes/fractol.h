/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:13 by susumuyagi        #+#    #+#             */
/*   Updated: 2024/04/29 15:28:38 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # define WINDOW_WIDTH 720
// # define WINDOW_HEIGHT 480
// # define WINDOW_WIDTH 1280
// # define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

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

	double				scale;
	double				dx;
	double				dy;

	int					is_down;
	double				down_x;
	double				down_y;
	int					keycode;

	t_data				img;

	int					progress;
	int					loop;

	int					color;
	int					(*model)(int, int, t_vars *);
	int					is_julia;
	double				c[2];
	double				*z;
	int					*count;
};

#endif
