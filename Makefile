# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 15:40:35 by hchahid           #+#    #+#              #
#    Updated: 2022/06/01 23:30:20 by ssadiki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

NAME_B = checker

HEADER = mandatory/push_swap.h

HEADER_B = bonus/checker_bonus.h

SRC = mandatory/t_list/ft_lstlast.c mandatory/t_list/ft_lstsize.c mandatory/t_list/ft_lstnew.c  \
	mandatory/t_list/init_stack.c  mandatory/t_list/ft_lstadd_back.c mandatory/t_list/destroy.c \
	mandatory/moves/push.c mandatory/moves/rotate.c mandatory/moves/swap.c mandatory/moves/doubles.c \
	mandatory/sorting/best_elm.c mandatory/sorting/handle_positions.c mandatory/sorting/return_b_to_a.c mandatory/sorting/sort_few.c \
	mandatory/sorting/min_a_to_top.c mandatory/sorting/calculate_position.c \
	mandatory/lis/lis.c mandatory/lis/setting_lis.c mandatory/lis/pushing_to_b.c \
	mandatory/utils/utils.c mandatory/utils/join_it.c mandatory/utils/utils1.c mandatory/utils/ft_split.c \
	mandatory/push_swap.c mandatory/errors/check_errors.c 

SRC_B = bonus/moves/push_bonus.c bonus/moves/rotate_bonus.c bonus/moves/swap_bonus.c bonus/moves/doubles_bonus.c \
	bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c\
	bonus/checker/checker.c bonus/checker/utils_bonus.c bonus/checker/utils1_bonus.c bonus/checker/ft_split_bonus.c\
	bonus/errors/check_errors_bonus.c \
	bonus/t_list/destroy_bonus.c bonus/t_list/ft_lstadd_back_bonus.c bonus/t_list/ft_lstlast_bonus.c bonus/t_list/ft_lstnew_bonus.c \
	bonus/t_list/ft_lstsize_bonus.c bonus/t_list/init_stack_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

RM = rm -f

$(NAME): $(OBJ) $(HEADER)
	cc $(OBJ) -o $(NAME)

$(NAME_B): $(OBJ_B) $(HEADER_B)
	cc $(OBJ_B) -o $(NAME_B)

%.o: %.c
	gcc -Wall -Wextra -Werror  -o $@ -c $< -g

all: $(NAME)

bonus: $(NAME_B)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean fclean
