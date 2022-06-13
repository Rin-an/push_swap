/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:27:59 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:28:03 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*c;
	char	*p;

	i = 0;
	p = (char *)s1;
	while (s1[i])
		i++;
	c = malloc((i + 1) * sizeof(char));
	if (!c)
		return (0);
	i = 0;
	while (p[i])
	{
		c[i] = p[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	r = malloc ((i + j + 1) * sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		r[i++] = s2[j++];
	r[i] = '\0';
	free(s1);
	return (r);
}

int	arg_lenght(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}
