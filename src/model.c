/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:11:44 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 16:13:53 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	to_z(int w, int h, double z[], t_vars *vars)
{
	z[0] = ((double)(w - vars->win_w / 2 + vars->dx)) / vars->scale * 0.005;
	z[1] = -((double)(h - vars->win_h / 2 + vars->dy)) / vars->scale * 0.005;
}

void	init_loop(t_vars *vars, int loop)
{
	vars->progress = 0;
	vars->loop = loop;
	if (loop < 0 || 1000000 < loop)
		vars->loop = 1000000;
}
