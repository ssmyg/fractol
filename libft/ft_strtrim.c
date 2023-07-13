/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:15:29 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/22 17:19:23 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	set_dict(char *dict, char const *set)
{
	ft_bzero(dict, 0xFF);
	while (*set)
	{
		dict[(unsigned char)*set] = 1;
		set++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	dict[0xFF];
	char	*t;

	if (!s1 || !set)
		return (NULL);
	set_dict(dict, set);
	t = (char *)s1;
	i = 0;
	while (*(t + i) && dict[(unsigned char)(*(t + i))])
		i++;
	start = i;
	while (*(t + i))
		i++;
	t--;
	while (start < i && dict[(unsigned char)(*(t + i))])
		i--;
	end = i;
	return (ft_substr(s1, start, end - start));
}
