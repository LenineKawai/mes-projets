/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:18:19 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 10:14:00 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_add_front(t_stack **alpha, t_stack *newb)
{
	if (alpha != NULL && newb != NULL)
	{
		newb->next = *alpha;
		*alpha = newb;
	}
}

t_stack	*ft_last(t_stack *lst)
{
	void	*p;

	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		p = lst;
		lst = lst->next;
	}
	return (p);
}

void	ft_add_back(t_stack **alpha, t_stack *newb)
{
	t_stack	*tmp;

	if (!alpha || !newb)
		return ;
	else if (!*alpha)
	{
		*alpha = newb;
		return ;
	}
	else
	{
		tmp = ft_last(*alpha);
		tmp->next = newb;
	}
}

t_stack	*ft_lstnew_int(int content)
{
	t_stack	*t_stack;

	t_stack = malloc(sizeof(*t_stack));
	if (!t_stack)
	{
		return (0);
	}
	t_stack->content = content;
	t_stack->simp = 0;
	t_stack->next = NULL;
	return (t_stack);
}

void	ft_clear(t_stack *lst)
{
	t_stack	*elem;

	elem = NULL;
	while (lst != NULL)
	{
		elem = lst;
		lst = lst->next;
		free(elem);
	}
}
