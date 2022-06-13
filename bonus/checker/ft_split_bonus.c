/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:27:45 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:27:47 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	nword(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && c != str[i])
			i++;
		if (c == 0)
		{
			count++;
			break ;
		}
		while (c && c == str[i])
			i++;
		count++;
	}
	return (count);
}

static int	wl(char *str, char c)
{
	int	count;

	count = 0;
	while (*str && c != *str)
	{
		count++;
		str++;
	}
	return (count);
}

static void	deallocate(char **result, int size)
{
	while (size--)
		free(result[size]);
	free(result);
}

static char	*fill(char *str, char c, char **word)
{
	int	wcount;
	int	j;

	wcount = wl(str, c);
	*word = malloc(sizeof(char) * (wcount + 1));
	if (!*word)
		return (0);
	j = 0;
	if (*word == 0)
		return (0);
	(*word)[wcount] = 0;
	while (j < wcount)
		(*word)[j++] = *str++;
	while (c == *str)
		str++;
	return (str);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		spcount;
	int		i;

	if (str == 0)
		return (NULL);
	while (c && *str && c == (char)*str)
		str++;
	spcount = nword((char *)str, c);
	result = malloc(sizeof(char *) * (spcount + 1));
	if (!result)
		return (0);
	result[spcount] = 0;
	i = 0;
	while (i < spcount)
	{
		str = fill((char *)str, c, result + i);
		if (str == 0)
		{
			deallocate(result, i);
			return (0);
		}
		i++;
	}
	return (result);
}
