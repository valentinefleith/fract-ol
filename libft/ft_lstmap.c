/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:48:06 by vafleith          #+#    #+#             */
/*   Updated: 2023/11/29 17:31:26 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rtn_lst;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	rtn_lst = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&rtn_lst, (del));
			return (NULL);
		}
		ft_lstadd_back(&rtn_lst, new);
		lst = lst->next;
	}
	return (rtn_lst);
}
