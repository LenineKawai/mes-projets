/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:18:26 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/16 11:10:39 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	while (*lst != NULL)
	{
		elem = (*lst);
		(*del)((*lst)->content);
		(*lst) = (*lst)->next;
		free(elem);
	}
	*lst = NULL;
}
