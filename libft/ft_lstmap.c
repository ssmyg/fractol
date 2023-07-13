/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:36:50 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/31 12:58:42 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new_lst);
		lst = lst->next;
	}
	return (ret);
}
