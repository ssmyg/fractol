/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:16:40 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/10/18 17:54:11 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "model.h"

int	mandelbrot(int w, int h, t_vars *vars)
{
	int		count;
	double	c[2];
	double	*z;
	double	tmp;

	to_z(w, h, c, vars);
	count = 0;
	z = &(vars->z[(h * WINDOW_WIDTH + w) * 2]);
	while (z[0] * z[0] + z[1] * z[1] < MAX_Z && count < vars->loop)
	{
		tmp = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2.0 * z[0] * z[1] + c[1];
		z[0] = tmp;
		count++;
	}
	vars->count[h * WINDOW_WIDTH + w] += count;
	if (count == vars->loop)
		return (-1);
	return (count);
}
/*
#include <stdio.h>

int	mandelbrot(int w, int h, t_vars *vars)
{
	double	c[2];
	double	a;
	int		b;

	to_z(w, h, c, vars);
	vars->count[h * WINDOW_WIDTH + w] = 10;
	if (0.0 < c[0] && c[0] < 0.025)
		vars->count[h * WINDOW_WIDTH + w] = 100;
	if (0.0 < c[1] && c[1] < 0.025)
		vars->count[h * WINDOW_WIDTH + w] = 100;
	b = 50;
	a = 1.0;
	if (a < c[0] && c[0] < a + 0.025 && -a < c[1] && c[1] < a)
		vars->count[h * WINDOW_WIDTH + w] = b;
	if (a < c[1] && c[1] < a + 0.025 && -a < c[0] && c[0] < a)
		vars->count[h * WINDOW_WIDTH + w] = b;
	if (-a - 0.025 < c[0] && c[0] < -a && -a < c[1] && c[1] < a)
		vars->count[h * WINDOW_WIDTH + w] = b;
	if (-a - 0.025 < c[1] && c[1] < -a && -a < c[0] && c[0] < a)
		vars->count[h * WINDOW_WIDTH + w] = b;
	b = 80;
	a = 0.5;
	if (a < c[0] && c[0] < a + 0.025 && -a < c[1] && c[1] < a)
		vars->count[h * WINDOW_WIDTH + w] = b;
	if (a < c[1] && c[1] < a + 0.025 && -a < c[0] && c[0] < a)
		vars->count[h * WINDOW_WIDTH + w] = b;
	if (-a - 0.025 < c[0] && c[0] < -a && -a < c[1] && c[1] < a)
		vars->count[h * WINDOW_WIDTH + w] = b;
	if (-a - 0.025 < c[1] && c[1] < -a && -a < c[0] && c[0] < a)
		vars->count[h * WINDOW_WIDTH + w] = b;
	return (vars->count[h * WINDOW_WIDTH + w]);
}
*/
