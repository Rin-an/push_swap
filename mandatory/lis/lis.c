/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:32:21 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:32:24 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_lis(int **p, int len)
{
	int	max;
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (p[0][i] > p[0][j] && (p[1][j] + 1) > p[1][i])
				p[1][i] += 1;
			j++;
		}
		i++;
	}
	i = 0;
	max = p[1][0];
	while (++i < len)
	{
		if (p[1][i] > max)
			max = p[1][i];
	}
	num_moves(p, len);
	return (max);
}

int	*extract_lis(int **p, int len, int len_lis)
{
	int	*lis;
	int	i;

	i = len - 1;
	lis = malloc (sizeof (int ) * len_lis);
	if (!lis)
		exit (0);
	while (i >= 0 && len_lis > 0)
	{
		if (p[1][i] == len_lis)
		{
			lis[len_lis - 1] = p[0][i];
			len_lis--;
		}
		i--;
	}
	free(p[1]);
	free(p[0]);
	return (lis);
}

void	find_lis(t_list **a, t_list **b)
{
	int	list_size;
	int	len_lis;
	int	**p;
	int	i;

	i = 0;
	p = NULL;
	list_size = ft_lstsize(*a);
	p = allocation(p, list_size);
	while (i < list_size)
		p[1][i++] = 1;
	p[0] = fill_values(p[0], *a);
	p[0] = sorted_arr(p[0], min_index(p, list_size), list_size);
	len_lis = calculate_lis(p, list_size);
	p[0] = extract_lis(p, list_size, len_lis);
	pb_not_in_lis(a, b, p[0], len_lis);
	free(p[0]);
	free(p);
}
