/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:21:01 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/28 11:21:01 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define HIDDEN	0
# define VERBOSE 1
# define DOUBLE_ROTATE 2
# define DOUBLE_REVERSE 3
# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	long	*stack;
	int		stack_length;
}	t_stack;

/*Basic instructions*/
void	swap(t_stack *s, char side, int verbose);
void	push(t_stack *a, t_stack *b, char side, int verbose);
void	rotate(t_stack *s, char side, int verbose);
void	reverse(t_stack *s, char side, int verbose);
void	rr(t_stack *a, t_stack *b, int action, int verbose);

/*Sorting utils*/
int		find_next(int number, t_stack *b);
int		get_pivot(int chunk, int length, int pivots);
int		get_cost(int index, t_stack *a);
void	bring_top(int number, t_stack *b);
void	pre_sort(t_stack *a, t_stack *b, int length, int pivots);

/*Sorting functions*/
void	sort(t_stack *a, t_stack *b, int pivots);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

/*Parsing and markup functions*/
int		is_sorted(t_stack *s);
int		ready_check(t_stack *a, t_stack *b);
void	normalize(t_stack *a);
void	ft_perror(char *msg);
void	parse_args(t_stack *stack_a, char **argv, int argc, int read_limit);
void	init_stacks(t_stack *a, t_stack *b, int argc);

/*General utils*/
int		tab_length(char **tab);
void	_init_check(int argc, char **argv, t_stack *a, t_stack *b);
void	ft_perror(char *msg);
void	free_tab(char **tab);
void	free_stacks(t_stack *a, t_stack *b);
#endif