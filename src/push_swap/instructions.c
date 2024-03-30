/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:45:42 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/28 10:45:42 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_stack *s, char side, int verbose)
{
	int	temp;

	if (s->stack_length < 2)
		return ;
	temp = s->stack[s->stack_length - 1];
	s->stack[s->stack_length - 1] = s->stack[s->stack_length - 2];
	s->stack[s->stack_length - 2] = temp;
	if (verbose)
		ft_printf("s%c\n", side);
}

void	push(t_stack *a, t_stack *b, char side, int verbose)
{
	if (side == 'a' && b->stack_length != 0)
	{
		a->stack_length++;
		a->stack[a->stack_length - 1] = b->stack[b->stack_length - 1];
		b->stack_length--;
	}
	if (side == 'b' && a->stack_length != 0)
	{
		b->stack_length++;
		b->stack[b->stack_length - 1] = a->stack[a->stack_length - 1];
		a->stack_length--;
	}
	if (verbose)
		ft_printf("p%c\n", side);
}

void	rotate(t_stack *s, char side, int verbose)
{
	int	j;
	int	temp;

	j = s->stack_length - 1;
	if (s->stack_length == 1)
		return ;
	while (j > 0)
	{
		temp = s->stack[j];
		s->stack[j] = s->stack[j - 1];
		s->stack[j - 1] = temp;
		j--;
	}
	if (verbose)
		ft_printf("r%c\n", side);
}

void	reverse(t_stack *s, char side, int verbose)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = s->stack_length - 1;
	if (s->stack_length == 1)
		return ;
	while (i < j)
	{
		temp = s->stack[i];
		s->stack[i] = s->stack[i + 1];
		s->stack[i + 1] = temp;
		i++;
	}
	if (verbose)
		ft_printf("rr%c\n", side);
}

void	rr(t_stack *a, t_stack *b, int action, int verbose)
{
	if (action == DOUBLE_ROTATE)
	{
		rotate(a, 0, HIDDEN);
		rotate(b, 0, HIDDEN);
		if (verbose)
			ft_printf("rr\n");
	}
	if (action == DOUBLE_REVERSE)
	{
		reverse(a, 0, HIDDEN);
		reverse(b, 0, HIDDEN);
		if (verbose)
			ft_printf("rrr\n");
	}
}
