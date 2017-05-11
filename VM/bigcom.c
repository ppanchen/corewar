/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigcom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:20:23 by amusel            #+#    #+#             */
/*   Updated: 2017/05/08 20:20:24 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_args			bigcom(int pc, t_args command, char *str)
{
	int	i;

	i = (int)ft_strlen(str) - 1;
	if (str[i] != '0' || str[i - 1] != '0')
		command.error = 2;
	if (str[i - 2] == '1' && str[i - 3] == '0')
		command.arg[2] = 1;
	else if (str[i - 2] == '0' && str[i - 3] == '1' && \
			command.op_code == 11)
		command.arg[2] = 2;
	else
		command.error = 2;
	if (command.op_code == 3)
	{
		command = parse_st(pc, command, str, i);
		return (command);
	}
	command = second_b(pc, command, str, i);
	return (command);
}

t_args			second_b(int pc, t_args command, char *str, int i)
{
	if (str[i - 4] == '1' && str[i - 5] == '0')
		command.arg[1] = 1;
	else if ((str[i - 4] == '0' && str[i - 5] == '1' && \
			(command.op_code == 10 || command.op_code == 11 || \
			command.op_code == 14)))
		command.arg[1] = 2;
	else if (str[i - 4] == '0' && str[i - 5] == '1')
		command.arg[1] = 4;
	else if ((str[i - 4] == '1' && str[i - 5] == '1') && \
			command.op_code != 10 && command.op_code != 14)
		command.arg[1] = 3;
	else
		command.error = 2;
	command = first_b(pc, command, str, i);
	return (command);
}

t_args			first_b(int pc, t_args command, char *str, int i)
{
	if ((str[i - 6] == '0' && str[i - 7] == '1' && \
			(command.op_code == 6 || command.op_code == 7 || \
			command.op_code == 8)))
		command.arg[0] = 4;
	else if (str[i - 6] == '0' && str[i - 6] == '1' && command.op_code != 11)
		command.arg[0] = 2;
	else if (str[i - 6] == '1' && str[i - 7] == '1' && command.op_code != 11)
		command.arg[0] = 3;
	else if (str[i - 6] == '1')
		command.arg[0] = 1;
	else
		command.error = 2;
	command = fill_command(pc, command);
	return (command);
}

t_args			fill_command(int pc, t_args command)
{
	int	temp[3];

	temp[0] = command.arg[0];
	temp[1] = command.arg[1];
	temp[2] = command.arg[2];
	if (command.arg[0] == 3)
	{
		temp[0] = 2;
		command.arg[0] = indir(pc, transfer(2, pc + 2), command);
	}
	else
		command.arg[0] = transfer(temp[0], pc + 2);
	if (command.arg[1] == 3)
	{
		temp[1] = 2;
		command.arg[1] = indir(pc, transfer(2, pc + temp[0] + 2), command);
	}
	else
		command.arg[1] = transfer(temp[1], pc + temp[0] + 2);
	command.arg[2] = transfer(temp[2], pc + temp[0] + temp[1] + 2);
	command.skip = temp[0] + temp[1] + temp[2] + 2;
	return (command);
}

t_args			ld_manage(int pc, t_args command, char *str)
{
	if (str[1] == '0')
	{
		command.arg[0] = transfer(4, pc + 2);
		command.arg[1] = g_field[pc + 6];
		command.skip = 7;
	}
	else
	{
		command.arg[0] = indir(pc, transfer(2, pc + 2), command);
		command.arg[1] = g_field[pc + 4];
		command.skip = 5;
	}
	return (command);
}
