/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:30:58 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/06/01 11:51:32 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	concatenate(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(dst + i))
		i++;
	while (*src && i + 1 < dstsize)
	{
		*(dst + i) = *src;
		i++;
		src++;
	}
	if (i + 1 > dstsize)
		*(dst + dstsize - 1) = '\0';
	if (i < dstsize)
		*(dst + i) = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	concatenate(dst, src, dstsize);
	return (src_len + dst_len);
}
