/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:32:01 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/06/28 13:05:32 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static ssize_t	write_format(va_list *ap, const char *fmt)
{
	ssize_t	len;

	if (*fmt == 'c')
		len = ft_putchar(va_arg(*ap, int));
	else if (*fmt == 's')
		len = ft_putstr(va_arg(*ap, char *));
	else if (*fmt == 'p')
		len = ft_putaddr(va_arg(*ap, void *));
	else if (*fmt == 'd')
		len = ft_putnbr(va_arg(*ap, int));
	else if (*fmt == 'i')
		len = ft_putnbr(va_arg(*ap, int));
	else if (*fmt == 'u')
		len = ft_putunbr(va_arg(*ap, unsigned int));
	else if (*fmt == 'x')
		len = ft_puthex(va_arg(*ap, unsigned int), 0);
	else if (*fmt == 'X')
		len = ft_puthex(va_arg(*ap, unsigned int), 1);
	else if (*fmt == '%')
		len = ft_putchar('%');
	else
		len = 0;
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	ssize_t	len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			len += write_format(&ap, ++fmt);
		else
			len += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (len);
}
