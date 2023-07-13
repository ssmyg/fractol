/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:22:33 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 16:54:07 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "model.h"
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

static int	valid_f_format(char *str)
{
	int	i;

	if (ft_strlen(str) != 7)
		return (0);
	if (str[0] != '+' && str[0] != '-')
		return (0);
	if (str[2] != '.')
		return (0);
	i = 1;
	while (i < 7)
	{
		if (i != 2 && (str[i] < '0' || '9' < str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	strtof(char *str, long double *x)
{
	int			sign;
	long double	ret;

	if (!valid_f_format(str))
		return (1);
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	ret = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			ret = ret * 10 + (*str - '0');
		str++;
	}
	ret = sign * ret / 10000.0;
	if (ret < -2.0 || 2.0 < ret)
		return (1);
	*x = ret;
	return (0);
}

int	set_arg(int argc, char *argv[], t_vars *vars)
{
	long double	x;

	if (argc == 1)
		return (1);
	if (set_model(argv[1], vars))
		return (1);
	if (argc >= 3)
	{
		if (strtof(argv[2], &x))
			return (1);
		vars->c[0] = x;
	}
	if (argc >= 4)
	{
		if (strtof(argv[3], &x))
			return (1);
		vars->c[1] = x;
	}
	return (0);
}

void	print_usage(void)
{
	ft_putstr("\
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
\n");
}
