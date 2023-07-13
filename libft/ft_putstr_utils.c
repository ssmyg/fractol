/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:27:52 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/06/28 13:09:20 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr(char *str)
{
	if (!str)
		return (write(STDOUT_FILENO, "(null)", 6));
	return (write(STDOUT_FILENO, str, ft_strlen(str)));
}

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
