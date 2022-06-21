/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:21:29 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/07 10:47:42 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	ft_check_strings(char **av, int nb_args)
{
	int	i;
	int	checker;

	checker = 0;
	if (nb_args == 2)
		i = 0;
	if (nb_args != 2)
		i = 1;
	while (av[i])
	{
		if (av[i][0] == 0)
			checker = 1;
		if (ft_check_inputs_are_digits(av, nb_args) == 1)
			checker = 1;
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
			checker = 1;
		i ++;
	}
	return (checker);
}

static int	ft_arg_checker(char **av, int ac, int nb_args)
{
	int	*array;
	int	checker;

	checker = ft_check_strings(av, nb_args);
	array = ft_turn_into_int_array(av, ac, nb_args);
	if (ft_check_for_dub(array, ac) == 1)
		checker = 1;
	else if (ft_is_sorted(array, ac, nb_args) == 0 || checker != 0)
	{
		if (checker == 1)
			ft_putstr_fd("Error\n", 2);
		free(array);
		return (1);
	}
	free(array);
	if (checker > 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

t_stack	*ft_stack_maker(char **av, t_stack *stack_to_make, int ac, int nb_args)
{
	int	i;

	if (nb_args == 2)
		i = 0;
	if (nb_args != 2)
		i = 1;
	stack_to_make = ft_lstnew_int(ft_atoi(av[i]));
	i ++;
	while (i < ac)
	{
		ft_add_back(&stack_to_make, ft_lstnew_int(ft_atoi(av[i])));
		i ++;
	}
	return (stack_to_make);
}

void	ft_two_args(t_stack **stack_a, t_stack **stack_b, char **av)
{
	char	**split;
	int		len;

	if (!av || av[1][0] == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	len = 0;
	split = ft_split(av[1], ' ');
	while (split[len])
		len ++;
	if (ft_arg_checker(split, len, 2) == 1)
	{
		ft_free(split);
		return ;
	}
	*stack_a = ft_stack_maker(split, *stack_a, len, 2);
	ft_free(split);
	ft_simplify(stack_a);
	if (len >= 2 && len <= 5)
		ft_sort_small_stack(stack_a, stack_b, len);
	else
		ft_radix(stack_a, stack_b);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	if (ac == 2)
	{
		ft_two_args(&stack_a, &stack_b, av);
	}
	if (ac != 2 && ft_arg_checker(av, ac, ac) == 0)
	{
		stack_a = ft_stack_maker(av, stack_a, ac, ac);
		ft_simplify(&stack_a);
		if (ac >= 3 && ac <= 6)
			ft_sort_small_stack(&stack_a, &stack_b, ac - 1);
		else
			ft_radix(&stack_a, &stack_b);
	}
	ft_free_stacks(&stack_a, &stack_b);
	return (0);
}
