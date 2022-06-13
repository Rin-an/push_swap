/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:33:10 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/04 18:54:30 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **a)
{
	t_list	*head;
	t_list	*tail;

	if (!*a)
		return ;
	head = *a;
	tail = ft_lstlast(*a);
	*a = (*a)->next;
	head->next = NULL;
	tail->next = head;
}

void	rb(t_list **b)
{
	t_list	*head;
	t_list	*tail;

	if (!*b)
		return ;
	head = *b;
	tail = ft_lstlast(*b);
	*b = (*b)->next;
	head->next = NULL;
	tail->next = head;
}

void	rra(t_list **a)
{
	t_list	*head;
	t_list	*tail;
	t_list	*top;
	int		len;
	int		i;

	if (!*a)
		return ;
	i = 1;
	head = *a;
	tail = *a;
	len = ft_lstsize(*a);
	while (i < len - 1)
	{
		tail = tail->next;
		i++;
	}
	top = ft_lstlast(*a);
	top->next = head;
	tail->next = NULL;
	*a = top;
}

void	rrb(t_list **b)
{
	t_list	*head;
	t_list	*tail;
	t_list	*top;
	int		len;
	int		i;

	if (!*b)
		return ;
	i = 1;
	head = *b;
	tail = *b;
	len = ft_lstsize(*b);
	while (i < len - 1)
	{
		tail = tail->next;
		i++;
	}
	top = ft_lstlast(*b);
	top->next = head;
	tail->next = NULL;
	*b = top;
}
