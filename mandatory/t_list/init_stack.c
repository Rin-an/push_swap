/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:35:18 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/07 13:59:29 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_value(t_list **a, char **av)
{
	int	i;

	i = 0;
	while (av[i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av[i++])));
}

void	init_position(t_list **a)
{
	t_list	*iter;
	int		len_a;
	int		i;

	i = 1;
	len_a = ft_lstsize(*a);
	iter = *a;
	while (i <= len_a / 2)
	{
		iter->position = i++;
		iter = iter->next;
	}
	while (i <= len_a)
	{
		if (i == len_a)
			iter->position = -1;
		else
			iter->position = i - len_a - 1;
		iter = iter->next;
		i++;
	}
}
