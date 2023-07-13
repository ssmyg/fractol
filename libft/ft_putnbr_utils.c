/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:44:59 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/06/28 13:05:22 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_nbr(int n, int sign, ssize_t *len)
{
	char	c;

	if (n / 10 != 0)
		write_nbr(n / 10, sign, len);
	c = (n % 10) * sign + '0';
	*len += write(STDOUT_FILENO, &c, 1);
}

ssize_t	ft_putnbr(int n)
{
	ssize_t	len;
	int		sign;

	len = 0;
	sign = 1;
	if (n < 0)
	{
		len += write(STDOUT_FILENO, "-", 1);
		sign = -1;
	}
	write_nbr(n, sign, &len);
	return (len);
}

static void	write_unbr(unsigned n, ssize_t *len)
{
	char	c;

	if (n / 10 != 0)
		write_unbr(n / 10, len);
	c = (n % 10) + '0';
	*len += write(STDOUT_FILENO, &c, 1);
}

ssize_t	ft_putunbr(unsigned int n)
{
	ssize_t	len;

	len = 0;
	write_unbr(n, &len);
	return (len);
}
