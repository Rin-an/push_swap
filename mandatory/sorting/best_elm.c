/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_elm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:33:33 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:33:40 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

// len represent the lenght of the moves in min_moves
// min_moves : return the index of the value that requires
// the least number of moves to be sorted in stack A

int	min_moves(int *moves, int len)
{
	int	min_i;
	int	i;

	i = 1;
	min_i = 0;
	while (i < len)
	{
		if (moves[i] < moves[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

// len represent the lenght of the tb in num_moves
// num_moves : the number of moves each node in stack B
// needs to be sorted in stack A

int	num_moves(int **tb, int len)
{
	int	*n_moves;
	int	min_i;
	int	i;

	i = 0;
	n_moves = malloc (sizeof (int ) * len);
	if (!n_moves)
		exit (0);
	while (i < len)
	{
		if (tb[0][i] >= 0 && tb[1][i] >= 0)
			n_moves[i] = (max(tb[0][i], tb[1][i]));
		else if (tb[0][i] < 0 && tb[1][i] < 0)
			n_moves[i] = abs(min(tb[0][i], tb[1][i]));
		else
			n_moves[i] = abs(tb[0][i]) + abs(tb[1][i]);
		i++;
	}
	min_i = min_moves(n_moves, len);
	free (n_moves);
	return (min_i);
}

int	**best_elm(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		len_a;
	int		len_b;
	int		**tb;
	int		i;

	i = -1;
	tmp = *b;
	tb = NULL;
	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	tb = allocation(tb, len_b);
	tb[0] = position_in_b(tb[0], len_b);
	while (++i < len_b)
	{
		init_position(a);
		tb[1][i] = position_in_a(a, len_a, tmp->value);
		tmp = tmp->next;
	}
	return (tb);
}
