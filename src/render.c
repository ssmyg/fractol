/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:15:02 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/14 15:45:38 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "fractol.h"
#include "render.h"
#include "mlx.h"
#include "model.h"
#include <limits.h>
#include <math.h>

static char	*get_pixel(int x, int y, t_data *img)
{
	return (img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
}

static int	is_complete(t_vars *vars)
{
	return (vars->progress >= vars->win_h * vars->win_w - 1);
}

static int	calc_pixel(int n, t_vars *vars)
{
	char	*dst;
	int		i;
	int		j;
	int		count;

	i = n % vars->win_w;
	j = n / vars->win_w;
	dst = get_pixel(i, j, &vars->img);
	if (*dst == 0)
	{
		count = vars->model(i, j, vars);
		if (count >= 0)
		{
			*(unsigned int *)dst = hsv2rgb(vars->color + sqrt(count * 10) * 10,
				255, 255);
			return (count);
		}
		else
		{
			*(unsigned int *)dst = 0;
			return (vars->loop);
		}
	}
	return (1);
}

int	render_frame(t_vars *vars)
{
	int	count;
	int	n;

	count = 0;
	n = vars->progress;
	while (n < vars->win_h * vars->win_w)
	{
		if (is_complete(vars) || count > OPE_PER_FLAME)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
			if (is_complete(vars))
				init_loop(vars, vars->loop * 2);
			return (0);
		}
		count += calc_pixel(n, vars);
		vars->progress = n;
		n++;
	}
	return (0);
}

void	drow_img(t_vars *vars)
{
	t_data	*img;

	init_loop(vars, INIT_LOOP);
	img = &vars->img;
	if (img->img)
		mlx_destroy_image(vars->mlx, img->img);
	img->img = mlx_new_image(vars->mlx, vars->win_w, vars->win_h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	render_frame(vars);
}
