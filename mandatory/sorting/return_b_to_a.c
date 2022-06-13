/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_b_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:34:14 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:34:15 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pos_moves(t_list **a, t_list **b, int **tb, int index)
{
	while (tb[0][index] > 0 && tb[1][index] > 0)
	{
		rr(a, b);
		tb[0][index] += -1;
		tb[1][index] += -1;
		str("rr\n");
	}
	while (tb[0][index] > 0)
	{
		rb(b);
		tb[0][index] += -1;
		str("rb\n");
	}
	while (tb[1][index] > 0)
	{
		ra(a);
		tb[1][index] += -1;
		str("ra\n");
	}
	pa(a, b);
}

void	neg_moves(t_list **a, t_list **b, int **tb, int index)
{
	while (tb[0][index] < 0 && tb[1][index] < 0)
	{
		rrr(a, b);
		tb[0][index] += 1;
		tb[1][index] += 1;
		str("rrr\n");
	}
	while (tb[0][index] < 0)
	{
		rrb(b);
		tb[0][index] += 1;
		str("rrb\n");
	}
	while (tb[1][index] < 0)
	{
		rra(a);
		tb[1][index] += 1;
		str("rra\n");
	}
	pa(a, b);
}

void	mixed_moves(t_list **a, t_list **b, int **tb, int index)
{
	handle_b_positions(b, tb, index);
	handle_a_positions(a, tb, index);
	pa(a, b);
}

int	**new_tb(int **tb, int index, int len)
{
	int	**new_tb;
	int	i;

	i = -1;
	new_tb = NULL;
	new_tb = allocation(new_tb, len);
	while (++i < len)
	{
		if (i == index)
			i++;
		new_tb[0][i] = tb[0][i];
		new_tb[1][i] = tb[1][i];
	}
	free(tb[0]);
	free(tb[1]);
	free(tb);
	return (new_tb);
}

// len represent the lenght of tb

void	push_to_a(t_list **a, t_list **b, int **tb)
{
	int	len_a;
	int	index;

	len_a = ft_lstsize(*a);
	while (ft_lstsize(*b))
	{
		index = num_moves(tb, ft_lstsize(*b));
		if (tb[0][index] >= 0 && tb[1][index] >= 0)
			pos_moves(a, b, tb, index);
		else if (tb[0][index] < 0 && tb[1][index] < 0)
			neg_moves(a, b, tb, index);
		else
			mixed_moves(a, b, tb, index);
		init_position(a);
		free(tb[0]);
		free(tb[1]);
		free(tb);
		tb = best_elm(a, b);
	}
	free(tb[0]);
	free(tb[1]);
	free(tb);
}
