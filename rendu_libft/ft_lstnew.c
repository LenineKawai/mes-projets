/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:07:48 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/16 11:12:17 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_list;

	t_list = malloc(sizeof(*t_list));
	if (!t_list)
	{
		return (0);
	}
	t_list->content = content;
	t_list->next = NULL;
	return (t_list);
}
