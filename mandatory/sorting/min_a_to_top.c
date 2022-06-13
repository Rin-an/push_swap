/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_a_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:34:03 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:34:04 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_elm_in_a(t_list *a, int len_a)
{
	int	min_i;
	int	min;
	int	i;

	i = -1;
	min_i = a->position;
	min = a->value;
	while (++i < len_a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_i = a->position;
		}
		a = a->next;
	}
	return (min_i);
}

void	min_a_to_top(t_list **a)
{
	int	min_elm;

	min_elm = min_elm_in_a(*a, ft_lstsize(*a));
	while (min_elm > 1)
	{
		ra(a);
		write(1, "ra\n", 3);
		min_elm--;
	}
	while (min_elm < 0)
	{
		rra(a);
		write(1, "rra\n", 4);
		min_elm++;
	}
}
