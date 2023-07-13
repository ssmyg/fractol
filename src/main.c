/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:11:44 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 16:16:37 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include "window.h"
#include <limits.h>
#include <stdio.h> // 後で消す
#include <stdlib.h>

char	*message(void)
{
	return "\
SYNOPSIS\n\
	fractol model [param1] [param2]\n\
\n\
DESCRIPTION\n\
	model	(mandelbrot | julia | sierpinski)\n\
	param1	parameter1 for Julia set (real part)\n\
	param2	parameter2 for Julia set (imaginary part)\n\
\n\
PARAMETER\n\
	Parameters are used only if Julia is selected as the model.\n\
\n\
	format	\"(+|-)d.dddd\" (e.g. +1.2345)\n\
	range	-2.0000 <= param <= +2.0000)\n\
\n\
USAGE\n\
	arrow	move the view\n\
	ESC	close window\n\
	s	shift color range\n\
	0	Restore the view to its initial state\n\
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
