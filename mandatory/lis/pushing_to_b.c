/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:32:31 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:32:32 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// tells us if value is part of the ongest increasing subsequence or not

int	in_lis(int *lis, int len_lis, int value)
{
	int	i;

	i = 0;
	while (i < len_lis)
	{
		if (lis[i] == value)
			return (1);
		i++;
	}
	return (0);
}

// len represent the lenght of the list
//to find where are the most elements not in LIS 

int	rra_or_ra(t_list **a, int *lis, int len, int len_lis)
{
	t_list	*tmp;
	int		rra;
	int		ra;
	int		i;

	i = 1;
	ra = 0;
	rra = 0;
	tmp = *a;
	while (i < len / 2)
	{
		if (!in_lis(lis, len_lis, tmp->value))
			ra++;
		i++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (!in_lis(lis, len_lis, tmp->value))
			rra++;
		tmp = tmp->next;
	}
	if (ra >= rra)
		return (1);
	return (0);
}

void	pb_with_ra(t_list **a, t_list **b, int *lis, int len_lis)
{
	while (ft_lstsize(*a) > len_lis)
	{
		if (!in_lis(lis, len_lis, (*a)->value))
			pb(a, b);
		else
		{
			ra(a);
			str("ra\n");
		}
	}
}

void	pb_with_rra(t_list **a, t_list **b, int *lis, int len_lis)
{
	while (ft_lstsize(*a) > len_lis)
	{
		if (!in_lis(lis, len_lis, (*a)->value))
			pb(a, b);
		else
		{
			rra(a);
			str("rra\n");
		}
	}
}

// pushing to B the elements that are not in LIS

void	pb_not_in_lis(t_list **a, t_list **b, int *lis, int len_lis)
{
	if (rra_or_ra(a, lis, ft_lstsize(*a), len_lis))
		pb_with_ra(a, b, lis, len_lis);
	else
		pb_with_rra(a, b, lis, len_lis);
}
