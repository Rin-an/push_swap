/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:33:47 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:33:49 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// position_in_b : how many moves for eash element in stack B to get to the top

int	*position_in_b(int *p, int size)
{
	int	i;

	i = -1;
	while (++i <= size / 2)
		p[i] = i;
	while (i < size)
	{
		p[i] = -1 * (size - i);
		i++;
	}
	return (p);
}

// max_elm_in_a : maximum value in stack a

int	max_elm_in_a(t_list *a, int len_a)
{
	int	max_i;
	int	max;
	int	i;

	i = -1;
	max_i = a->position;
	max = a->value;
	while (++i < len_a)
	{
		if (a->value > max)
		{
			max = a->value;
			max_i = a->position;
		}
		a = a->next;
	}
	if (max_i >= 0)
		return (max_i);
	else
		return (max_i + 1);
}

int	biggest_a_from_b(t_list **a, int value)
{
	t_list	*iter;

	iter = *a;
	while (iter)
	{
		if (value < iter->value)
			return (0);
		iter = iter->next;
	}
	return (1);
}

// position_in_a : where value should be placed in stack A
// with least number of moves between ra and rra

int	position_in_a(t_list **a, int len_a, int value)
{
	t_list	*tail;
	t_list	*head;
	int		i;

	i = -1;
	head = *a;
	tail = ft_lstlast(*a);
	if (biggest_a_from_b(a, value))
		return (max_elm_in_a(*a, len_a));
	while (++i < len_a)
	{
		if (head->next && value > head->value && value < head->next->value)
		{
			if (head->position < 0)
				return (head->position + 1);
			return (head->position);
		}
		head = head->next;
	}
	return (0);
}
