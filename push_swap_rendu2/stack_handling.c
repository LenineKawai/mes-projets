/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:04:42 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 11:36:35 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_last_elem(t_stack *lst)
{
	void	*p;
	int		i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		p = lst;
		lst = lst->next;
		i ++;
	}
	return (i);
}

void	ft_swap(t_stack **stack, char identifier)
{
	int		swp;
	int		simp;
	t_stack	*tmp_p;

	if (ft_last_elem(*stack) < 2 || *stack == NULL)
		return ;
	tmp_p = (*stack)->next;
	swp = (*stack)->content;
	simp = (*stack)->simp;
	(*stack)->content = tmp_p->content;
	(*stack)->simp = tmp_p->simp;
	tmp_p->content = swp;
	tmp_p->simp = simp;
	if (identifier == 'b')
		write(1, "sb\n", 3);
	if (identifier == 'a')
		write(1, "sa\n", 3);
}

void	ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	int		swp;
	t_stack	*tmp_p;

	if (ft_last_elem(*stack_a) < 2 || stack_a == NULL || stack_b == NULL)
		return ;
	tmp_p = (*stack_a)->next;
	swp = (*stack_a)->content;
	(*stack_a)->content = tmp_p->content;
	tmp_p->content = swp;
	if (ft_last_elem(*stack_b) < 2)
		return ;
	tmp_p = (*stack_b)->next;
	swp = (*stack_b)->content;
	(*stack_b)->content = tmp_p->content;
	tmp_p->content = swp;
}

void	ft_push(t_stack **stack_from, t_stack **stack_to, char identifier)
{
	t_stack	*tmp;

	if (*stack_from == NULL)
		return ;
	tmp = (*stack_from)->next;
	ft_add_front(stack_to, *stack_from);
	*stack_from = tmp;
	if (identifier == 'b')
		write(1, "pb\n", 3);
	if (identifier == 'a')
		write(1, "pa\n", 3);
}
