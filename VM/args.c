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
	int				ret;

	i = -1;
	while (++i < 4)
		arr[i] = 0;
	i = -1;
	while (++i < amount)
		arr[(amount - 1) - i] = g_field[chk(pc + i)];
	pointer = (int*)arr;
	ret = *pointer;
	return (ret);
}

t_args			parse_st(int pc, t_args command, char *str, int i)
{
	if (ft_strcmp(str, "1010000") == 0)
	{
		command.error = 0;
		command.arg[0] = g_field[chk(pc + 2)];
		command.arg[1] = g_field[chk(pc + 3)];
		command.error += (command.arg[0] > 16 || command.arg[0] == 0) ? 2 : 0;
		command.error += (command.arg[1] > 16 || command.arg[1] == 0) ? 2 : 0;
		command.skip = 4;
	}
	else if (ft_strcmp(str, "1110000") == 0)
	{
		command.error = 0;
		command.arg[0] = g_field[chk(pc + 2)];
		command.arg[1] = transfer(2, chk(pc + 3));
		command.skip = 5;
		command.error += (command.arg[0] > 16 || command.arg[0] == 0) ? 2 : 0;
	}
	else
		command.error = 2;
	return (command);
}

t_args			litcom(int pc, t_args command, char *str)
{
	if (command.op_code == 16 && ft_strcmp(str, "10000000") == 0)
	{
		command.arg[0] = g_field[chk(pc + 2)];
		command.error += (command.arg[0] > 16 || command.arg[0] == 0) ? 2 : 0;
		command.skip = 3;
	}
	else if ((command.op_code == 4 || command.op_code == 5) && \
			ft_strcmp(str, "1010100") == 0)
	{
		command.arg[0] = g_field[chk(pc + 2)];
		command.arg[1] = g_field[chk(pc + 3)];
		command.arg[2] = g_field[chk(pc + 4)];
		command.skip = 5;
		command = reg(command, NULL);
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

	command.op_code = g_field[chk(pc)];
	if ((command.op_code == 1 || command.op_code == 9 || \
		command.op_code == 12 || command.op_code == 15))
	{
		command.coding_byte = 0;
		command.arg[0] = transfer(2, chk(pc + 1));
		command.skip = 3;
		if (command.op_code == 1)
		{
			command.arg[0] = transfer(4, chk(pc + 1));
			command.skip = 5;
		}
		return (command);
	}
	else
		command.coding_byte = g_field[chk(pc + 1)];
	str = ft_itoa_base_uup((int)command.coding_byte, 2);
	command = litcom(pc, command, str);
	return (command);
}

t_args			reg(t_args command, int *temp)
{
	if (command.op_code == 4 || command.op_code == 5)
	{
		command.error += (command.arg[0] > 16 || command.arg[0] == 0) ? 2 : 0;
		command.error += (command.arg[1] > 16 || command.arg[1] == 0) ? 2 : 0;
		command.error += (command.arg[2] > 16 || command.arg[2] == 0) ? 2 : 0;
		return (command);
	}
	if (temp[0] == 1)
		command.error += (command.arg[0] > 16 || command.arg[0] == 0) ? 2 : 0;
	if (temp[1] == 1)
		command.error += (command.arg[1] > 16 || command.arg[1] == 0) ? 2 : 0;
	if (temp[2] == 1)
		command.error += (command.arg[2] > 16 || command.arg[2] == 0) ? 2 : 0;
	return (command);
}
