/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:25:59 by amusel            #+#    #+#             */
/*   Updated: 2017/05/08 20:26:00 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				chk(int pc)
{
	if (pc >= 4096)
		pc -= 4096;
	return (pc);
}

t_args			parse_op(int pc, unsigned char op_code)
{
	t_args	command;
	char	*str;

	command = clean_arg();
	command.op_code = op_code;
	command = get_op(pc, command);
	if (command.error > 0)
	{
		str = ft_itoa_base_uup((int)command.coding_byte, 2);
		command = error_small(command, str);
		command = error_big(command, str);
		free(str);
	}
	if (command.op_code > 17 || command.op_code < 0)
	{
		command.error = 1;
		command.skip = 1;
	}
	return (command);
}

int				indir(int pc, int tns, t_args command)
{
	int		ret;
	char	am;

	am = (char)(g_tab[command.op_code - 1].direct_len == 1 ? 2 : 4);
	if (command.op_code == 13 || command.op_code == 14)
	{
		ret = pc + (short)tns;
		if (ret >= 4096)
			ret -= 4096;
		ret = transfer(am, ret);
	}
	else
	{
		ret = pc + ((short)tns % IDX_MOD);
		if (ret >= 4096)
			ret -= 4096;
		ret = transfer(am, ret);
	}
	return (ret);
}
