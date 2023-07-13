/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:16:40 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 16:16:24 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "model.h"
#include <math.h>

int	func(double x, double y, int depth, int max)
{
	double	t;

	t = pow(0.5, depth);
	if (depth > max)
		return (max * 17);
	if (x < 0)
		return (-1);
	if (y < 0)
		return (-1);
	if (x + y > 1)
		return (-1);
	if (x + y > t * 3.0 && x < t * 3.0 && y < t)
		return (-1);
	if (x + y > t * 3.0 && x < t && y < t * 3.0)
		return (-1);
	if (x + y > t && x < t && y < t)
		return (-1);
	if (x > t)
		return (func(x - t, y, depth + 1, max));
	if (y > t)
		return (func(x, y - t, depth + 1, max));
	return (func(x, y, depth + 1, max));
}

int	sierpinski(int w, int h, t_vars *vars)
{
	int		max;
	double	c[2];

	to_z(w, h, c, vars);
	max = log10(vars->scale) * 3 + 8;
	return (func(c[0], c[1], 0, max));
}
