/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:28:12 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:28:14 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	r;
	int		s;

	r = 0;
	s = 1;
	i = 0;
	while (space(str[i]))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	r *= s;
	if (r > 2147483647 || r < -2147483648)
		ft_error(2);
	return (r);
}

int	space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}

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
