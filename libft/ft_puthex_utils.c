/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:44:59 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/06/28 13:09:02 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_hex(unsigned int n, ssize_t *len, int is_upper)
{
	char	c;

	if (n / 16 != 0)
		write_hex(n / 16, len, is_upper);
	c = HEX_BASE[n % 16];
	if (is_upper)
		c = ft_toupper(c);
	*len += write(STDOUT_FILENO, &c, 1);
}

ssize_t	ft_puthex(unsigned int n, int is_upper)
{
	ssize_t	len;

	len = 0;
	write_hex(n, &len, is_upper);
	return (len);
}

static void	write_addr(unsigned long n, ssize_t *len)
{
	char	c;

	if (n / 16 != 0)
		write_addr(n / 16, len);
	c = HEX_BASE[n % 16];
	*len += write(STDOUT_FILENO, &c, 1);
}

ssize_t	ft_putaddr(void *p)
{
	ssize_t			len;
	unsigned long	n;

	n = (unsigned long)p;
	len = 0;
	len += write(STDOUT_FILENO, "0x", 2);
	write_addr(n, &len);
	return (len);
}
