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

t_args			parse_op(int pc)
{
	t_args command;

	command = clean_arg();
	command = get_op(pc, command);
	if (command.op_code > 17 || command.op_code == 0)
		command.error = 1;
	if (command.error > 0)
		command.skip = 1;
	return (command);
}

int				indir(int pc, int tns, t_args command)
{
	int	ret;

	if (command.op_code == 13 || command.op_code == 14)
	{
		ret = pc + tns;
		if (ret >= 4096)
			ret -= 4096;
		ret = transfer(2, ret);
	}
	else
	{
		ret = pc + (tns % IDX_MOD);
		if (ret >= 4096)
			ret -= 4096;
		ret = transfer(2, ret);
	}
	return (ret);
}