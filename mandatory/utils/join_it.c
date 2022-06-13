/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:35:35 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:35:36 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**join_it(char **av)
{
	char	**arg;
	char	*str;
	int		i;

	i = 1;
	str = NULL;
	while (av[i])
	{
		str = ft_strjoin(str, av[i++]);
		str = ft_strjoin(str, " ");
	}
	arg = ft_split(str, ' ');
	free(str);
	return (arg);
}
