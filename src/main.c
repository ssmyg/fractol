/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:11:44 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/11 14:48:01 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <limits.h>
#include <stdio.h> // 後で消す
#include <stdlib.h>

void	to_z(int w, int h, double z[], t_vars *vars)
{
	z[0] = ((double)(w - vars->win_w / 2 + vars->dx)) / vars->scale * 0.005;
	z[1] = -((double)(h - vars->win_h / 2 + vars->dy)) / vars->scale * 0.005;
}

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	drow_img(&vars);
	set_hooks(&vars);
	return (0);
}

// 画像が荒くなる
//--------- move [427, 537] (-9804279408184684.000000,
//	-49169586665984112.000000) 0x16b205f00 -46299400465567.914062
// zoom: -268228477880337312.000000 -13233340686353.125000 671787610756710.12
