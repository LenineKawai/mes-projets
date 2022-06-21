/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:12:55 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 11:02:47 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*scd;
	t_stack	*trd;
	t_stack	*fst;

	scd = ft_b_last(*stack_a);
	trd = ft_last(*stack_a);
	fst = *stack_a;
	if (ft_sorted_list(stack_a) == 0)
		return ;
	if (trd->content > scd->content && trd->content > fst->content)
		ft_swap(stack_a, 'a');
	else if (fst->content > scd->content && scd->content > trd->content)
	{
		ft_swap(stack_a, 'a');
		ft_reverse_rotate(stack_a, 'a');
	}
	else if (fst->content > scd->content && scd->content < trd->content)
		ft_rotate(stack_a, 'a');
	else if (fst->content < scd->content && fst->content < trd->content)
	{
		ft_swap(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (scd->content > fst->content && trd->content < scd->content)
		ft_reverse_rotate(stack_a, 'a');
}

static void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_smallest(*stack_a, 0);
	ft_rotate_list(stack_a, i, 0);
	ft_push(stack_a, stack_b, 'b');
	ft_sort_three(stack_a);
	ft_push(stack_b, stack_a, 'a');
}

static void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	searched_simp;

	searched_simp = 0;
	while (searched_simp < 2)
	{
		i = ft_smallest(*stack_a, searched_simp);
		ft_rotate_list(stack_a, i, searched_simp);
		ft_push(stack_a, stack_b, 'b');
		searched_simp ++;
	}
	ft_sort_three(stack_a);
	ft_push(stack_b, stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
}

void	ft_sort_small_stack(t_stack **stack_a, t_stack **stack_b, int ac)
{
	(void)stack_b;
	if (ac == 2)
		ft_swap(stack_a, 'a');
	else if (ac == 3)
	{
		ft_sort_three(stack_a);
	}
	else if (ac == 4)
	{
		ft_sort_four(stack_a, stack_b);
	}
	else if (ac == 5)
	{
		ft_sort_five(stack_a, stack_b);
	}
}
