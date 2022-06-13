/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:27:29 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:28:20 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"
#include "../get_next_line/get_next_line.h"

int	is_sorted(t_list **a, t_list **b)
{
	t_list	*iter;

	iter = *a;
	if (*b)
		return (0);
	while (iter->next)
	{
		if (iter->next && (iter->value > iter->next->value))
			return (0);
		iter = iter->next;
	}
	return (1);
}

void	exec_instructions(char *instr, t_list **a, t_list **b)
{
	if (!(ft_strcmp(instr, "sa")))
		sa(a);
	else if (!(ft_strcmp(instr, "sb")))
		sb(b);
	else if (!(ft_strcmp(instr, "ss")))
		ss(a, b);
	else if (!(ft_strcmp(instr, "pa")))
		pa(a, b);
	else if (!(ft_strcmp(instr, "pb")))
		pb(a, b);
	else if (!(ft_strcmp(instr, "ra")))
		ra(a);
	else if (!(ft_strcmp(instr, "rb")))
		rb(b);
	else if (!(ft_strcmp(instr, "rr")))
		rr(a, b);
	else if (!(ft_strcmp(instr, "rra")))
		rra(a);
	else if (!(ft_strcmp(instr, "rrb")))
		rrb(b);
	else if (!(ft_strcmp(instr, "rrr")))
		rrr(a, b);
	else
		str("Error\n");
}

void	get_instruction(t_list **a, t_list **b)
{
	char		*instr;

	while (get_next_line(&instr))
	{
		if (!instr)
			break ;
		if (instr[3] == '\n' || instr[2] == '\n')
		{
			if (instr[3] == '\n')
				instr[3] = '\0';
			else
				instr[2] = '\0';
		}
		else if (instr[3] != '\n')
			str("Error\n");
		exec_instructions(instr, a, b);
	}
}

void	str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write (1, &s[i++], 1);
	if (!(ft_strcmp(s, "Error\n")))
		exit(1);
}

int	main(int ac, char **av)
{
	char	**arg;
	char	**tmp;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	arg = join_it(av);
	ac = arg_lenght(arg);
	check_errors(ac, arg);
	init_value(&a, arg);
	get_instruction(&a, &b);
	if (is_sorted(&a, &b))
		str("OK\n");
	else
		str("KO\n");
	destroy_list(a);
	tmp = arg;
	while (*arg)
		free(*arg++);
	free(tmp);
}
