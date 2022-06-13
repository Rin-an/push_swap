/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:32:40 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:32:40 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	**allocation(int **p, int len)
{
	p = malloc(sizeof(int *) * 2);
	if (!p)
		exit(0);
	p[0] = malloc(sizeof(int ) * (len));
	if (!p[0])
		exit(0);
	p[1] = malloc(sizeof(int ) * (len));
	if (!p[1])
		exit(0);
	return (p);
}

int	min_index(int **p, int len)
{
	int	i;
	int	min_i;

	i = 1;
	min_i = 0;
	while (i < len)
	{
		if (p[0][i] < p[0][min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

int	*fill_values(int *p, t_list *a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		p[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (p);
}

int	*sorted_arr(int *p, int min_i, int len)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = malloc(sizeof(int ) * len);
	if (!tmp)
		exit (0);
	i = 0;
	j = min_i;
	while (j < len)
		tmp[i++] = p[j++];
	j = 0;
	while (j < min_i)
		tmp[i++] = p[j++];
	free(p);
	return (tmp);
}
