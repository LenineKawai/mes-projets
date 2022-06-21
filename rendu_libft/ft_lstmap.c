/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:09:37 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/15 13:55:23 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	if (!lst || !f)
		return (0);
	tmp = (ft_lstnew(f(lst->content)));
	new_list = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp = (ft_lstnew(f(lst->content)));
		if (!tmp)
		{
			ft_lstclear(&new_list, (*del));
			return (0);
		}
		ft_lstadd_back(&new_list, tmp);
	}
	return (new_list);
}
