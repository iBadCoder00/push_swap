/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:06:02 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/28 18:06:02 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest(t_stack *a)
{
	int		i;
	int		j;
	long	big;

	i = 0;
	j = 0;
	big = a->stack[0];
	while (i < a->stack_length)
	{
		if (a->stack[i] > big)
		{
			big = a->stack[i];
			j = i;
		}
		i++;
	}
	a->stack[j] = LONG_MIN;
	return (j);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->stack_length - 1)
	{
		if (s->stack[i] != s->stack[i + 1] + 1)
			return (0);
		i++;
	}
	return (1);
}

int	ready_check(t_stack *a, t_stack *b)
{
	if (is_sorted(a) || a->stack_length <= 1)
		return (1);
	if (a->stack_length <= 3)
	{
		sort_three(a);
		return (1);
	}
	if (a->stack_length <= 5)
	{
		sort_five(a, b);
		return (1);
	}
	return (0);
}

void	init_stacks(t_stack *a, t_stack *b, int argc)
{
	a->stack = malloc(sizeof(long) * (argc - 1));
	b->stack = malloc(sizeof(long) * (argc - 1));
	if (!a->stack || !b->stack)
		exit(1);
	a->stack_length = argc - 1;
	b->stack_length = 0;
}

void	normalize(t_stack *a)
{
	int		i;
	int		j;
	long	*aux;

	i = 0;
	aux = malloc(sizeof(long) * a->stack_length);
	if (!aux)
		exit(1);
	while (i < a->stack_length)
	{
		j = get_highest(a);
		aux[j] = a->stack_length - 1 - i;
		i++;
	}
	free(a->stack);
	a->stack = aux;
}
