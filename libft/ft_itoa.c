/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:42:07 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/25 08:55:16 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_len(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	set_nbr_str(char *str, int n, size_t len)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[len - 1] = '0' + sign * (n % 10);
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	len;

	len = count_len(n);
	if (n < 0)
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	set_nbr_str(ret, n, len);
	return (ret);
}
