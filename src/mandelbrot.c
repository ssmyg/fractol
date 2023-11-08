/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:16:40 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/11/08 15:26:38 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "model.h"

int	mandelbrot(int w, int h, t_vars *vars)
{
	int			count;
	long double	c[2];
	long double	*z;
	long double	tmp;

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
