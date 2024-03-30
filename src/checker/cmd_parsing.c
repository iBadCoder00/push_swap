/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:47:58 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/30 11:47:58 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_command(t_stack *a, t_stack *b, char *cmd)
{
	int			i;
	static char	*valid_cmds[12]
		= {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", 0};

	i = 0;
	while (valid_cmds[i])
	{
		if (ft_strncmp(cmd, valid_cmds[i], ft_strlen(valid_cmds[i])) == 0)
		{
			do_cmd(a, b, valid_cmds[i]);
			return ;
		}
		i++;
	}
	ft_perror("Error\n");
}

void	get_cmd(t_stack *a, t_stack *b)
{
	static char	*line = "";

	while (line)
	{
		line = get_next_line(0);
		if (line)
			parse_command(a, b, line);
		free(line);
	}
}
