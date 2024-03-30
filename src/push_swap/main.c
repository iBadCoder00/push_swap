/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:07:43 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/28 18:07:43 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_pivot(int stack_length)
{
	int	pivots;

	pivots = 0;
	if (stack_length <= 10)
		pivots = 2;
	else if (stack_length <= 100)
		pivots = 4;
	else if (stack_length <= 500)
		pivots = 7;
	else
		pivots = 11;
	return (pivots);
}

int	main(int argc, char **argv)
{
	int		pivots;
	t_stack	stack_a;
	t_stack	stack_b;

	_init_check(argc, argv, &stack_a, &stack_b);
	if (ready_check(&stack_a, &stack_b))
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	pivots = set_pivot(stack_a.stack_length);
	sort(&stack_a, &stack_b, pivots);
	free_stacks(&stack_a, &stack_b);
}
