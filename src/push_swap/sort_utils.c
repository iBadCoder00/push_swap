/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:43:17 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/28 10:43:17 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_top(int number, t_stack *b)
{
	int	i;

	i = 0;
	while (b->stack[i] != number && i < b->stack_length)
		i++;
	while (b->stack[b->stack_length - 1] != number)
	{
		if (i < b->stack_length / 2)
			reverse(b, 'b', VERBOSE);
		else
			rotate(b, 'b', VERBOSE);
	}
}

int	find_next(int number, t_stack *b)
{
	int	i;
	int	j;
	int	cost;

	i = b->stack_length - 1;
	j = -1;
	cost = INT_MAX;
	while (i >= 0)
	{
		if (number > b->stack[i])
		{
			if (abs(get_cost(i, b)) < cost)
			{
				cost = abs(get_cost(i, b));
				j = i;
			}
		}
		i--;
	}
	if (cost == INT_MAX)
		return (cost);
	else
		return (b->stack[j]);
}

int	get_pivot(int chunk, int length, int pivots)
{
	int	pivot;

	pivot = ((chunk - 1) * (length / pivots) + (chunk) * (length / pivots)) / 2;
	return (pivot);
}

int	get_cost(int index, t_stack *a)
{
	if (index < a->stack_length / 2)
		return (-(index + 1));
	else
		return (a->stack_length - (index + 1));
}

void	pre_sort(t_stack *a, t_stack *b, int length, int pivots)
{
	int	j;
	int	pivot;

	j = 1;
	while (j < pivots)
	{
		pivot = get_pivot(j, length, pivots);
		while (a->stack_length > length - j * (length / pivots))
		{
			if (a->stack[a->stack_length - 1] <= (j * (length / pivots)))
			{
				if (a->stack[a->stack_length - 1] < pivot)
				{
					push(a, b, 'b', VERBOSE);
					rotate(b, 'b', VERBOSE);
				}
				else
					push(a, b, 'b', VERBOSE);
			}
			else
				rotate(a, 'a', VERBOSE);
		}
		j++;
	}
}
