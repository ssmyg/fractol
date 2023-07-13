/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:59:48 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/25 10:15:42 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	while (*s && start)
	{
		s++;
		start--;
	}
	i = 0;
	while (s[i] && i < len)
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	i = 0;
	while (s[i] && i < len)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
