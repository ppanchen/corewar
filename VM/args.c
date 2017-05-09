/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 14:14:57 by amusel            #+#    #+#             */
/*   Updated: 2017/05/06 14:15:00 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				transfer(int amount, int pc)
{
	int				i;
	unsigned char	arr[4];
	int				*pointer;
	int 			ret;

	i = -1;
	while (++i < 4)
		arr[i] = 0;
	i = -1;
	while (++i < amount)
		arr[(amount - 1) - i] = g_field[pc + i];
	pointer = (int*)arr;
	ret = *pointer;
	return (ret);
}

t_args			parse_st(int pc, t_args command, char *str, int i)
{
	if (ft_strcmp(str, "1010000") == 0)
	{
		command.error = 0;
		command.arg[0] = g_field[pc + 2];
		command.arg[1] = g_field[pc + 3];
		command.skip = 4;
	}
	else if (ft_strcmp(str, "1110000") == 0)
	{
		command.error = 0;
		command.arg[0] = g_field[pc + 2];
		command.arg[1] = transfer(2, pc + 3);
		command.skip = 5;
	}
	else
		command.error = 1;
	return (command);
}

t_args			litcom(int pc, t_args command, char *str)
{
	if (command.op_code == 16 && ft_strcmp(str, "10000000") == 0)
	{
		command.arg[0] = transfer(4, pc + 2);
		command.skip = 6;
	}
	else if ((command.op_code == 4 || command.op_code == 5) && \
			ft_strcmp(str, "1010100") == 0)
	{
		command.arg[0] = g_field[pc + 2];
		command.arg[1] = g_field[pc + 3];
		command.arg[2] = g_field[pc + 4];
		command.skip = 5;
	}
	else if ((command.op_code == 13 || command.op_code == 2) && \
			(ft_strcmp(str, "10010000") == 0 || \
			ft_strcmp(str, "11010000") == 0))
		command = ld_manage(pc, command, str);
	else
		command = bigcom(pc, command, str);
	return (command);
}

t_args			get_op(int pc, t_args command)
{
	char	*str;

	command.op_code = g_field[pc];
	if ((command.op_code == 1 || command.op_code == 9 || \
		command.op_code == 12 || command.op_code == 15))
	{
		command.coding_byte = 0;
		command.arg[0] = transfer(2, pc + 1);
		command.skip = 3;
		if (command.op_code == 1)
		{
			command.arg[0] = transfer(4, pc + 1);
			command.skip = 5;
		}
		return (command);
	}
	else
		command.coding_byte = g_field[pc + 1];
	str = ft_itoa_base_uup((int)command.coding_byte, 2);
	command = litcom(pc, command, str);
	return (command);
}
