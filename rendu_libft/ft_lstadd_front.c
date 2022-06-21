/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:07:57 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/15 18:01:37 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alpha, t_list *newb)
{
	if (alpha != NULL && newb != NULL)
	{
		newb->next = *alpha;
		*alpha = newb;
	}
}
