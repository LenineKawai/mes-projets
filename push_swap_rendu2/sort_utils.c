/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:55:15 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 10:57:55 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_sorted_list(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = (*stack)->next;
	while (tmp2 != NULL)
	{
		if (tmp->content > tmp2->content)
			return (1);
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	return (0);
}

int	ft_smallest(t_stack *stack, int searched_simp)
{
	int	i;

	i = 0;
	while (stack->simp != searched_simp)
	{
		stack = stack->next;
		i ++;
	}
	return (i);
}

void	ft_rotate_list(t_stack **stack, int i, int searched_simp)
{
	if (i > 0)
	{
		if (i == 1)
			ft_swap(stack, 'a');
		else if (i == 2)
		{
			ft_rotate(stack, 'a');
			ft_swap(stack, 'a');
		}
		else
			while ((*stack)->simp != searched_simp)
				ft_reverse_rotate(stack, 'a');
	}
}
