/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:46:31 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/18 12:21:15 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				content;
	int				simp;	
	struct s_stack	*next;
}					t_stack;

int		ft_sorted_list(t_stack **stack);
int		ft_smallest(t_stack *stack, int searched_simp);
int		*ft_turn_into_int_array(char **av, int len, int nb_args);
int		ft_check_inputs_are_digits(char **av, int nb_args);
int		ft_is_sorted(int *array, int len, int nb_args);
int		ft_check_for_dub(int *array, int len);
int		ft_last_elem(t_stack *lst);
void	ft_free(char **to_free);
void	ft_free_stacks(t_stack **stack_a, t_stack **stack_b);
void	ft_add_back(t_stack **alpha, t_stack *newb);
void	ft_clear(t_stack *lst);
void	ft_swap(t_stack **stack, char identifier);
void	ft_push(t_stack **stack_from, t_stack **stack_to, char identifier);
void	ft_add_front(t_stack **alpha, t_stack *newb);
void	ft_rotate(t_stack **stack, char identifier);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack, char identifier);
void	ft_rr_both(t_stack **stack_a, t_stack **stack_b);
void	ft_simplify(t_stack **stack_a);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);
void	ft_display(t_stack *stack);
void	ft_sort_small_stack(t_stack **stack_a, t_stack **stack_b, int ac);
void	ft_rotate_list(t_stack **stack, int i, int searched_simp);
t_stack	*ft_stack_maker(char **av, t_stack *stack_to_make, int ac, int nb_args);
t_stack	*ft_lstnew_int(int content);
t_stack	*ft_last(t_stack *lst);
t_stack	*ft_b_last(t_stack *lst);

#endif
