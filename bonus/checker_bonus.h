/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:28:35 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/02 21:28:37 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_list
{
	int				value;
	int				position;
	struct s_list	*next;

}	t_list;

/*******************************************
------------- ERROR MANAGEMENT -------------
********************************************/

void	ft_error(int std);
void	is_num(char *av);
void	check_errors(int ac, char **av);
void	check_duplicates(int ac, char **av);

/*******************************************/

/**************************************************
---------------- STACK MANAGEMENT -----------------
***************************************************/

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);
int		ft_lstsize(t_list *lst);
void	destroy_list(t_list	*a);
void	init_value(t_list **a, char **av);

/**************************************************/

/*********************************
---------- OPERATIONS ------------
**********************************/

void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

/***********************************/
/*********************************
------------ UTILS -------------
**********************************/

int		arg_lenght(char **av);
char	*ft_strjoin(char *s1, char *s2);
void	str(char *s);
int		ft_atoi(const char *str);
int		space(char c);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *str, char c);
char	**join_it(char **av);
/************************************************************/
int		is_sorted(t_list **a, t_list **b);
void	exec_instructions(char *instr, t_list **a, t_list **b);
void	get_instruction(t_list **a, t_list **b);
#endif
