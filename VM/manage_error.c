/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:45:37 by amusel            #+#    #+#             */
/*   Updated: 2017/05/12 14:45:39 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_args			error_bigg(t_args command, char *str, int i)
{
	if (str[i - 4] == '1' && str[i - 5] == '1')
		command.arg[1] = 2;
	else if (str[i - 4] == '0' && str[i - 5] == '1')
		command.arg[1] = 4;
	else if (str[i - 4] == '1' && str[i - 5] != '1')
		command.arg[1] = 1;
	if (str[i - 6] == '1' && str[i - 7] == '1')
		command.arg[0] = 2;
	else if (str[i - 6] == '0' && str[i - 7] == '1')
		command.arg[0] = 4;
	else if (str[i - 6] == '1' && str[i - 7] != '1')
		command.arg[0] = 1;
	return (command);
}

t_args			error_bi(t_args command, char *str, int i)
{
	if (str[i - 4] == '1' && str[i - 5] == '1' && \
		command.op_code == 11)
		command.arg[1] = 2;
	else if (str[i - 4] == '0' && str[i - 5] == '1')
		command.arg[1] = 2;
	else if (str[i - 4] == '1' && str[i - 5] != '1')
		command.arg[1] = 1;
	if (str[i - 6] == '1' && str[i - 7] == '1' && \
		command.op_code != 11)
		command.arg[0] = 2;
	else if (str[i - 6] == '0' && str[i - 7] == '1' && \
			command.op_code != 11)
		command.arg[0] = 2;
	else if (str[i - 6] == '1' && str[i - 7] != '1')
		command.arg[0] = 1;
	return (command);
}

t_args			error_big(t_args command, char *str)
{
	int i;

	i = (int)ft_strlen(str) - 1;
	if (str[i - 2] == '1' && str[i - 3] != '1')
		command.arg[2] = 1;
	else if (str[i - 2] == '0' && str[i - 3] == '1' && command.op_code == 11)
		command.arg[2] = 2;
	if (command.op_code == 6 || command.op_code == 7 || \
		command.op_code == 8)
		error_bigg(command, str, i);
	else
		error_bi(command, str, i);
	if (command.skip == 0)
		command.skip = command.arg[0] + command.arg[1] +
				command.arg[2] + 2;
	command.arg[0] = 0;
	command.arg[1] = 0;
	command.arg[2] = 0;
	return (command);
}

t_args			error_smalll(t_args command, char *str, int i)
{
	if (command.op_code == 2 || command.op_code == 13)
	{
		if (str[i - 6] == '1' && str[i - 7] == '1')
			command.arg[0] = 2;
		if (str[i - 6] == '0' && str[i - 7] == '1')
			command.arg[0] = 4;
	}
	else if (str[i - 6] == '1' && str[i - 7] != '1')
		command.arg[0] = 1;
	return (command);
}

t_args			error_small(t_args command, char *str)
{
	int i;

	i = (int)ft_strlen(str) - 1;
	if (command.op_code == 16)
	{
		command.skip = 2;
		return (command);
	}
	if ((str[i - 2] == '1' && str[i - 3] != '1') && \
		(command.op_code == 4 || command.op_code == 5))
		command.arg[2] = 1;
	if ((str[i - 4] == '1' && str[i - 5] == '1') &&
		command.op_code == 3)
		command.arg[1] = 2;
	else if (str[i - 4] == '1' && str[i - 5] != '1')
		command.arg[1] = 1;
	command = error_smalll(command, str, i);
	i = command.op_code;
	if (i == 2 || i == 3 || i == 4 || i == 5 || i == 13)
		command.skip = command.arg[0] + command.arg[1] +
				command.arg[2] + 2;
	command.arg[0] = 0;
	command.arg[1] = 0;
	command.arg[2] = 0;
	return (command);
}
