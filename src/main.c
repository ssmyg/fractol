/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:11:44 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 16:52:15 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include "render.h"
#include "window.h"
#include <limits.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_vars	vars;

	init_vars(&vars);
	if (set_arg(argc, argv, &vars))
	{
		print_usage();
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
