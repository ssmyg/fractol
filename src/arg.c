/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:22:33 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 11:17:27 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	set_model(char *str, t_vars *vars)
{
	if (!ft_strcmp(str, "mandelbrot"))
		vars->model = mandelbrot;
	else if (!ft_strcmp(str, "julia"))
		vars->model = julia;
	else if (!ft_strcmp(str, "sierpinski"))
		vars->model = sierpinski;
	else
		return (1);
	return (0);
}
/*
static double	str2f(char *str)
{
}

*/
int	set_arg(int argc, char *argv[], t_vars *vars)
{
	(void)argv;
	if (argc == 1)
		return (1);
	if (set_model(argv[1], vars))
		return (1);
	return (0);
}
