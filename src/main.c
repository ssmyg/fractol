/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:11:44 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 12:38:09 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <limits.h>
#include <stdio.h> // 後で消す
#include <stdlib.h>

void	to_z(int w, int h, double z[], t_vars *vars)
{
	z[0] = ((double)(w - vars->win_w / 2 + vars->dx)) / vars->scale * 0.005;
	z[1] = -((double)(h - vars->win_h / 2 + vars->dy)) / vars->scale * 0.005;
}

char	*message(void)
{
	return "\
SYNOPSIS\n\
	fractol model [param1] [param2]\n\
\n\
DESCRIPTION\n\
	model: (mandelbrot | julia | sierpinski)\n\
	param1: parameter1 for Julia set (real part)\n\
	param2: parameter2 for Julia set (imaginary part)\n\
\n\
PARAMETER\n\
	format: \"d.dddd\" (e.g. 1.2345)\n\
	range: -2.0000 <= param <= 2.0000)\n\
\n\
USAGE\n\
	arrow keys :\tmove the view\n\
	ESC :\t\tclose window\n\
	s :\t\tshift color range\n\
	0 :\t\tRestore the view to its initial state\n\
\n\
";
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	init_vars(&vars);
	if (set_arg(argc, argv, &vars))
	{
		ft_putstr(message());
		return (0);
	}
	init_window(&vars);
	drow_img(&vars);
	set_hooks(&vars);
	return (0);
}

// 画像が荒くなる
//--------- move [427, 537] (-9804279408184684.000000,
//	-49169586665984112.000000) 0x16b205f00 -46299400465567.914062
// zoom: -268228477880337312.000000 -13233340686353.125000 671787610756710.12
