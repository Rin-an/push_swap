/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:34:21 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:34:22 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	index_max(t_list	**a)
{
	t_list	*iter;
	int		max_i;
	int		max;
	int		i;

	iter = *a;
	max = iter->value;
	max_i = 1;
	i = 1;
	while (iter)
	{
		if (iter->value > max)
		{
			max = iter->value;
			max_i = i;
		}
		iter = iter->next;
		i++;
	}
	return (max_i);
}

int	is_sorted(t_list *a)
{
	while (a)
	{
		if (a->next && (a->value > (a->next)->value))
			return (0);
	}
	return (1);
}

void	sort_two(t_list **a)
{
	if (is_sorted(*a))
		return ;
	sa(a);
	str("sa\n");
}

void	sort_three(t_list **a)
{
	int		max_i;

	max_i = index_max(a);
	if (ft_lstsize(*a) == 2)
	{
		sort_two(a);
		return ;
	}
	if (max_i == 1)
	{
		ra(a);
		str("ra\n");
	}
	else if (max_i == 2)
	{
		rra(a);
		str("rra\n");
	}
	if (((*a)->next)->value < (*a)->value)
	{
		sa(a);
		str("sa\n");
	}
}

void	sort_five(t_list **a, t_list **b)
{
	init_position(a);
	if (ft_lstsize(*a) == 5)
	{
		min_a_to_top(a);
		pb(a, b);
		init_position(a);
		min_a_to_top(a);
		pb(a, b);
	}
	else
	{
		min_a_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	if (ft_lstsize(*b) == 2)
	{
		if ((*b)->value < ((*b)->next)->value)
			sb(b);
	}
	while (ft_lstsize(*b))
		pa(a, b);
}
