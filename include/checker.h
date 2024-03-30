/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:58:48 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/29 13:58:48 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

void	do_swap(t_stack *a, t_stack *b, char *cmd);
void	do_rotate(t_stack *a, t_stack *b, char *cmd);
void	do_reverse(t_stack *a, t_stack *b, char *cmd);
void	do_cmd(t_stack *a, t_stack *b, char *cmd);
void	parse_command(t_stack *a, t_stack *b, char *cmd);
void	get_cmd(t_stack *a, t_stack *b);
#endif // CHECKER_H