/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:47:05 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 10:48:55 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_simplify(t_stack **stack_a)
{
	int		simp;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*stack_a);
	tmp2 = (*stack_a);
	simp = 0;
	while (tmp != NULL)
	{
		tmp2 = (*stack_a);
		simp = 0;
		while (tmp2 != NULL)
		{
			if (tmp->content > tmp2->content)
				simp ++;
			tmp2 = tmp2->next;
		}
		tmp->simp = simp;
		tmp = tmp->next;
	}
}
