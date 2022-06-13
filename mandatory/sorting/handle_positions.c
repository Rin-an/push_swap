/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:33:56 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:33:57 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_b_positions(t_list **b, int **tb, int index)
{
	if (tb[0][index] > 0)
	{
		while (tb[0][index] > 0)
		{
			rb(b);
			tb[0][index] += -1;
			str("rb\n");
		}
	}
	else
	{
		while (tb[0][index] < 0)
		{
			rrb(b);
			tb[0][index] += 1;
			str("rrb\n");
		}
	}
}

void	handle_a_positions(t_list **a, int **tb, int index)
{
	if (tb[1][index] > 0)
	{
		while (tb[1][index] > 0)
		{
			ra(a);
			tb[1][index] += -1;
			str("ra\n");
		}
	}
	else
	{
		while (tb[1][index] < 0)
		{
			rra(a);
			tb[1][index] += 1;
			str("rra\n");
		}
	}
}
