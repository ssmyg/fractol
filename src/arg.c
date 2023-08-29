/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:22:33 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/08/29 17:10:44 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "model.h"
#include <math.h>

static int	set_model(char *str, t_vars *vars)
{
	if (!ft_strcmp(str, "mandelbrot"))
		vars->model = mandelbrot;
	else if (!ft_strcmp(str, "julia"))
	{
		vars->model = julia;
		vars->is_julia = 1;
	}
	else if (!ft_strcmp(str, "sierpinski"))
		vars->model = sierpinski;
	else
		return (1);
	return (0);
}

static int	invalid_f_format(char *str)
{
	int	dot_num;

	if (ft_strlen(str) > 9)
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (1);
	if (*str == '.')
		return (1);
	dot_num = 0;
	while (*str)
	{
		if (*str == '.')
			dot_num++;
		else if (*str < '0' || '9' < *str)
			return (1);
		str++;
	}
	if (*(--str) == '.')
		return (1);
	if (dot_num >= 2)
		return (1);
	return (0);
}

static double	tof(char *str, int sign)
{
	double	ret;
	int		dot_position;
	int		i;

	i = 0;
	ret = 0;
	dot_position = -1;
	while (str[i])
	{
		if (str[i] == '.')
			dot_position = ft_strlen(str) - i - 1;
		if ('0' <= str[i] && str[i] <= '9')
			ret = ret * 10 + (str[i] - '0');
		i++;
	}
	ret = sign * ret;
	if (dot_position > 0)
		ret /= pow(10.0, dot_position);
	return (ret);
}

static int	strtof(char *str, double *x)
{
	int		sign;
	double	ret;

	if (invalid_f_format(str))
		return (1);
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	ret = tof(str, sign);
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
	if (argc >= 3 && !vars->is_julia)
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
	if (argc >= 5)
		return (1);
	return (0);
}
