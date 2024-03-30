/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:44:15 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/28 10:44:15 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *string)
{
	long	number;
	long	sign;

	number = 0;
	sign = 1;
	if (!string)
		return (0);
	while ((*string >= 9 && *string <= 13) || *string == 32)
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign *= -1;
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		number = number * 10 + *string - '0';
		string++;
	}
	return (number * sign);
}

static void	check_dup(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->stack_length)
	{
		j = i + 1;
		while (j < s->stack_length)
		{
			if (s->stack[i] == s->stack[j])
				ft_perror("Error\n");
			j++;
		}
		i++;
	}
}

void	parse_args(t_stack *stack_a, char **argv, int argc, int read_limit)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (argc >= read_limit)
	{
		j = 0;
		len = ft_strlen(argv[argc]);
		stack_a->stack[i] = ft_atol(argv[argc]);
		while (argv[argc][j])
		{
			if (!isdigit(argv[argc][j]))
				if ((argv[argc][j] != '-' && argv[argc][j] != '+')
					|| j != 0 || len <= 1)
					ft_perror("Error\n");
			j++;
		}
		if (stack_a->stack[i] > INT_MAX || stack_a->stack[i] < INT_MIN
			|| len == 0)
			ft_perror("Error\n");
		i++;
		argc--;
	}
	check_dup(stack_a);
}
