/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:21:42 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/23 19:20:04 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**malloc_ret(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**ret;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[0] != c)
			count++;
		else if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ret)
		return (NULL);
	ret[count] = NULL;
	return (ret);
}

static size_t	word_len(char const *s, char c, size_t i)
{
	size_t	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static void	free_ret(char **ret, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

static int	split(char const *s, char c, char **ret)
{
	size_t	i;
	size_t	k;
	size_t	len;
	char	*word;

	i = 0;
	k = 0;
	while (s[i])
	{
		len = 0;
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
			len = word_len(s, c, i);
		if (len > 0)
		{
			word = ft_substr(s, i, len);
			if (!word)
			{
				free_ret(ret, k);
				return (0);
			}
			ret[k++] = word;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = malloc_ret(s, c);
	if (!ret)
		return (NULL);
	if (!split(s, c, ret))
		return (NULL);
	return (ret);
}
