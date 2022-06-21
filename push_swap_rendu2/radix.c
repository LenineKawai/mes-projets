/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:55:54 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 10:45:03 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	ft_binary_nbr_size(int max_num)
{
	int	i;

	i = 0;
	while (max_num != 0)
	{
		max_num /= 2;
		i ++;
	}
	return (i);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_num;
	int	max_bit;
	int	i;
	int	j;

	max_num = ft_last_elem(*stack_a) - 1;
	max_bit = ft_binary_nbr_size(max_num);
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < max_num + 1)
		{
			if ((((*stack_a)->simp >> i) & 1) == 1)
			{
				ft_rotate(stack_a, 'a');
			}
			else
				ft_push(stack_a, stack_b, 'b');
			j ++;
		}
		while (*stack_b != NULL)
			ft_push(stack_b, stack_a, 'a');
		i ++;
	}
}
