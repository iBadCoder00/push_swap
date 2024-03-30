/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:55:51 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/29 13:55:51 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack *a, t_stack *b, char *cmd)
{
	swap(a, cmd[1], HIDDEN);
	swap(b, cmd[1], HIDDEN);
}

void	do_swap(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd[1] == 'a')
		swap(a, cmd[1], HIDDEN);
	else if (cmd[1] == 'b')
		swap(b, cmd[1], HIDDEN);
	else
		ss(a, b, cmd);
}

void	do_rotate(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd[1] == 'a')
		rotate(a, cmd[1], HIDDEN);
	else if (cmd[1] == 'b')
		rotate(b, cmd[1], HIDDEN);
	else
		rr(a, b, DOUBLE_ROTATE, HIDDEN);
}

void	do_reverse(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd[2] == 'a')
		reverse(a, cmd[1], HIDDEN);
	else if (cmd[2] == 'b')
		reverse(b, cmd[1], HIDDEN);
	else
		rr(a, b, DOUBLE_REVERSE, HIDDEN);
}

void	do_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd[0] == 'p')
		push(a, b, cmd[1], HIDDEN);
	else if (cmd[0] == 's')
		do_swap(a, b, cmd);
	else if (cmd[0] == 'r' && cmd[2] == '\n')
		do_rotate(a, b, cmd);
	else
		do_reverse(a, b, cmd);
}
