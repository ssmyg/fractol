/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:13:05 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/06/01 11:38:05 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match_needle(const char *haystack, const char *needle, size_t i,
		size_t len)
{
	while (*needle && *haystack && i < len)
	{
		if (*haystack != *needle)
			return (0);
		haystack++;
		needle++;
		i++;
	}
	if (*needle == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (len == 0 && (!haystack || !needle))
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		if (*haystack == *needle)
			if (is_match_needle(haystack, needle, i, len))
				return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
