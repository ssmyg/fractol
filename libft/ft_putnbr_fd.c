/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:44:41 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/25 09:12:10 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_nbr(int n, int sign, int fd)
{
	if (n / 10 != 0)
		write_nbr(n / 10, sign, fd);
	ft_putchar_fd((n % 10) * sign + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	write_nbr(n, sign, fd);
}
