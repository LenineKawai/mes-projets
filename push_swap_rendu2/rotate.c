/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:39:29 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 10:47:14 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*ft_b_last(t_stack *lst)
{
	void	*p;

	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		p = lst;
		lst = lst->next;
	}
	return (p);
}

void	ft_rotate(t_stack **stack, char identifier)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	last = ft_last(*stack);
	*stack = (*stack)->next;
	last->next = tmp;
	tmp->next = NULL;
	if (identifier == 'b')
		write(1, "rb\n", 3);
	if (identifier == 'a')
		write(1, "ra\n", 3);
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	tmp = *stack_a;
	last = ft_last(*stack_a);
	*stack_a = (*stack_a)->next;
	last->next = tmp;
	tmp->next = NULL;
	tmp = *stack_b;
	last = ft_last(*stack_b);
	*stack_b = (*stack_b)->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate(t_stack **stack, char identifier)
{
	t_stack	*b_last;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	last = ft_last(*stack);
	b_last = ft_b_last(*stack);
	last->next = *stack;
	*stack = last;
	b_last->next = NULL;
	if (identifier == 'b')
		write(1, "rrb\n", 4);
	if (identifier == 'a')
		write(1, "rra\n", 4);
}

void	ft_rr_both(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_last;
	t_stack	*last;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	last = ft_last(*stack_a);
	b_last = ft_b_last(*stack_a);
	last->next = *stack_a;
	*stack_a = last;
	b_last->next = NULL;
	last = ft_last(*stack_b);
	b_last = ft_b_last(*stack_b);
	last->next = *stack_b;
	*stack_b = last;
	b_last->next = NULL;
	write(1, "rrr\n", 4);
}
