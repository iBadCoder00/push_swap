/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:47:50 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/28 09:47:50 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_remainder(t_stack *a, t_stack *b, int initial_length)
{
	while (a->stack_length > 3)
	{
		if (a->stack[a->stack_length - 1] != initial_length - 1)
			push(a, b, 'b', VERBOSE);
		else
			rotate(a, 'a', VERBOSE);
	}
}

static void	push_back(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (b->stack_length > 0)
	{
		i = find_next(a->stack[a->stack_length - 1], b);
		if (i == INT_MAX)
			rotate(a, 'a', VERBOSE);
		else
		{
			bring_top(i, b);
			push(a, b, 'a', VERBOSE);
		}
	}
}

void	sort_three(t_stack *a)
{
	if (a->stack[1] > a->stack[0] && a->stack[1] > a->stack[2])
		reverse(a, 'a', VERBOSE);
	else if (a->stack[2] > a->stack[0] && a->stack[2] > a->stack[1])
		rotate(a, 'a', VERBOSE);
	if (a->stack[1] < a->stack[0] && a->stack[1] < a->stack[2])
		swap(a, 'a', VERBOSE);
	else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2])
		reverse(a, 'a', VERBOSE);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	initial_length;

	initial_length = a->stack_length;
	push_remainder(a, b, initial_length);
	sort_three(a);
	push_back(a, b);
	while (a->stack[a->stack_length - 1] != 0)
		rotate(a, 'a', VERBOSE);
}

void	sort(t_stack *a, t_stack *b, int pivots)
{
	int	initial_length;

	initial_length = a->stack_length;
	pre_sort(a, b, initial_length, pivots);
	push_remainder(a, b, initial_length);
	sort_three(a);
	push_back(a, b);
	while (a->stack[a->stack_length - 1] != 0)
		rotate(a, 'a', VERBOSE);
}
