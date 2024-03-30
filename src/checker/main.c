/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:55:35 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/29 13:55:35 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	_init_check(argc, argv, &stack_a, &stack_b);
	get_cmd(&stack_a, &stack_b);
	if (is_sorted(&stack_a) && stack_b.stack_length == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&stack_a, &stack_b);
}
