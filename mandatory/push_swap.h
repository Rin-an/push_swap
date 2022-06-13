/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:31:57 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/07 14:22:26 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<math.h>

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
void	init_position(t_list **a);

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

/***********************************************************************
------------------------------- SORTING --------------------------------
***********************************************************************/

void	find_lis(t_list **a, t_list **b);

int		**allocation(int **p, int ac);
int		*fill_values(int *p, t_list *a);
int		min_index(int **p, int len);
int		*sorted_arr(int *p, int min_i, int len);

int		calculate_lis(int **p, int len);
int		*extract_lis(int **p, int len, int len_lis);

void	pb_not_in_lis(t_list **a, t_list **b, int *lis, int len_lis);
int		rra_or_ra(t_list **a, int *lis, int len, int len_lis);
int		in_lis(int *lis, int len_lis, int value);

int		**best_elm(t_list **a, t_list **b);

int		num_moves(int **tb, int len);
int		min_moves(int *moves, int len);
int		position_in_a(t_list **a, int len_a, int value);
int		max_elm_in_a(t_list *a, int len_a);
int		biggest_a_from_b(t_list **a, int value);
int		*position_in_b(int *p, int size);
int		max(int a, int b);
int		min(int a, int b);

void	push_to_a(t_list **a, t_list **b, int **tb);

void	pos_moves(t_list **a, t_list **b, int **tb, int index);
void	neg_moves(t_list **a, t_list **b, int **tb, int index);
void	mixed_moves(t_list **a, t_list **b, int **tb, int index);
void	handle_b_positions(t_list **b, int **tb, int index);
void	handle_a_positions(t_list **a, int **tb, int index);
int		**new_tb(int **tb, int index, int len);

int		min_elm_in_a(t_list *a, int len_a);
void	min_a_to_top(t_list **a);

void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b);

/************************************************************************/

/****************************************
----------------- UTILS -----------------
*****************************************/

int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *str, char c);
void	str(char *s);
char	**ft_split(char const *str, char c);
char	**join_it(char **av);
int		arg_length(char **av);

/*****************************************/

#endif
