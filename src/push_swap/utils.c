/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:47:02 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/30 11:47:02 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_perror(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
}

int	tab_length(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	_init_check(int argc, char **argv, t_stack *a, t_stack *b)
{
	char	**tab;

	tab = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab[0])
			ft_perror("Error\n");
		argc = tab_length(tab);
		init_stacks(a, b, argc + 1);
		parse_args(a, tab, argc - 1, 0);
		free_tab(tab);
	}
	else
	{
		init_stacks(a, b, argc);
		parse_args(a, argv, argc - 1, 1);
	}
	normalize(a);
}
