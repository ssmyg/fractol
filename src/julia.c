/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:16:40 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/12 11:53:07 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	julia(int w, int h, t_vars *vars)
{
	int		count;
	double	c[2];
	double	z[2];
	double	tmp;

	to_z(w, h, c, vars);
	count = 0;
	z[0] = c[0];
	z[1] = c[1];
	while (z[0] * z[0] + z[1] * z[1] < MAX_Z && count < vars->loop)
	{
		tmp = z[0] * z[0] - z[1] * z[1] - 0.3;
		z[1] = 2.0 * z[0] * z[1] - 0.63;
		z[0] = tmp;
		count++;
	}
	if (count == vars->loop)
		return (0);
	// if (count < 50)
	return (hsv2rgb(100 + count * 7, 255, 255));
	//	return (hsv2rgb(130 + count * 7, 255, 255));
	// else
	//		return (hsv2rgb(130 + count, 255, 255));
	// return (hsv2rgb(130 + count, 255, 255));
}
