/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:11:44 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/10/10 14:20:05 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <limits.h>

void	to_z(int w, int h, double z[], t_vars *vars)
{
	z[0] = ((double)(w - WINDOW_WIDTH / 2 + vars->dx)) / vars->scale * 0.005;
	z[1] = -((double)(h - WINDOW_HEIGHT / 2 + vars->dy)) / vars->scale * 0.005;
}

void	init_loop(t_vars *vars, int loop)
{
	int	i;

	vars->progress = 0;
	if (loop)
	{
		vars->loop = loop;
		i = 0;
		while (i < WINDOW_WIDTH * WINDOW_HEIGHT * 2)
		{
			vars->z[i] = 0.0;
			i++;
		}
		i = 0;
		while (i < WINDOW_WIDTH * WINDOW_HEIGHT)
		{
			vars->count[i] = 0;
			i++;
		}
	}
	else
	{
		if (vars->loop < INT_MAX / 1.5)
			vars->loop = vars->loop * 1.5;
	}
}
