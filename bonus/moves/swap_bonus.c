/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:30:27 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:30:28 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	sa(t_list **a)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	if (!tmp)
		return ;
	(*a)->next = (*a)->next->next;
	tmp->next = *a;
	*a = tmp;
}

void	sb(t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	if (!tmp)
		return ;
	(*b)->next = (*b)->next->next;
	tmp->next = *b;
	*b = tmp;
}
