/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:32:07 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:32:09 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(int std)
{
	write(std, "ERROR\n", 6);
	exit(0);
}

void	check_errors(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		is_num(av[i]);
		i++;
	}
	i = 0;
	check_duplicates(ac, av);
}

void	is_num(char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		ft_error(2);
	if ((av[i] == '+' || av[i] == '-')
		&& (av[i + 1] >= '0' && av[i + 1] <= '9'))
			i++;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			ft_error(2);
		i++;
	}
}

void	check_duplicates(int ac, char **av)
{
	int	i;
	int	j;
	int	*t;

	i = 0;
	j = 0;
	t = (int *)malloc(sizeof (int) * (ac));
	if (!t)
		exit (0);
	while (av[i])
		t[j++] = ft_atoi(av[i++]);
	i = -1;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
		{
			if (t[i] == t[j])
			{
				free(t);
				ft_error(2);
			}
		}
	}
	free(t);
}
