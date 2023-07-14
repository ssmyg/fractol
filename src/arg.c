/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:22:33 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/14 15:53:54 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "model.h"

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

static int	strtof(char *str, double *x)
{
	int		sign;
	double	ret;

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
	double	x;

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
