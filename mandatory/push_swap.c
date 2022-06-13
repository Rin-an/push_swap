/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:31:51 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/07 14:16:26 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_stack(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->next && (tmp->value > tmp->next->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	manage_args(int ac, char **arg, t_list **a, t_list **b)
{
	int		len_a;

	if (ac == 1)
		exit (1);
	init_value (a, arg);
	if (is_sorted_stack(a))
	{
		destroy_list(*a);
		exit(0);
	}
	len_a = ft_lstsize(*a);
	if (len_a < 6)
	{
		if (len_a < 4)
			sort_three(a);
		else
			sort_five(a, b);
		exit (1);
	}
	find_lis(a, b);
	push_to_a(a, b, best_elm(a, b));
	min_a_to_top(a);
	destroy_list(*a);
}

int	main(int ac, char **av)
{
	char	**arg;
	char	**tmp;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	arg = join_it(av);
	ac = arg_lenght(arg);
	check_errors(ac, arg);
	manage_args(ac, arg, &a, &b);
	tmp = arg;
	while (*arg)
		free(*arg++);
	free(tmp);
}
