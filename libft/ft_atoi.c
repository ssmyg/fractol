/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:41:31 by syagi             #+#    #+#             */
/*   Updated: 2023/06/01 10:05:41 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static char	*skip_space(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	return (str);
}

static int	occer_overflow(char *str, long sign, long ret)
{
	if (sign == 1)
	{
		if (LONG_MAX / 10 < ret)
			return (1);
		if (LONG_MAX - ret * 10 < sign * (*str - '0'))
			return (1);
	}
	else if (sign == -1)
	{
		if (LONG_MIN / 10 > ret)
			return (1);
		if (LONG_MIN - ret * 10 > sign * (*str - '0'))
			return (1);
	}
	return (0);
}

static long	ft_strtol(char *str)
{
	long	sign;
	long	ret;

	str = skip_space(str);
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ret = 0;
	while (*str != '\0' && '0' <= *str && *str <= '9')
	{
		if (occer_overflow(str, sign, ret))
		{
			if (sign == 1)
				return (LONG_MAX);
			else if (sign == -1)
				return (LONG_MIN);
		}
		ret = ret * 10 + sign * (*str - '0');
		str++;
	}
	return (ret);
}

int	ft_atoi(char *str)
{
	return ((int)ft_strtol(str));
}
