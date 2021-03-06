/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:34:39 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:34:40 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	destroy_list(t_list	*a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
