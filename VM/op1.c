/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:10:08 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/08 22:10:10 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int						ft_add(t_process *process, t_player *player)
{
	(void *)player;
	if (!process->args.error)
	{
		process->reg[process->args.arg[2] - 1] =
				process->reg[process->args.arg[0] - 1] +
				process->reg[process->args.arg[1] - 1];

		process->carry_flag = (char) (process->reg[process->args.arg[2] - 1]
									  == 0 ? 1 : 0);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int						ft_sub(t_process *process, t_player *player)
{
	(void *)player;
	if (!process->args.error)
	{
		process->reg[process->args.arg[2] - 1] =
				process->reg[process->args.arg[0] - 1] -
				process->reg[process->args.arg[1] - 1];
//		(g_debug_flag) ? printf("\n       | %i %i %i",
//							process->reg[process->args.arg[0] - 1],
//							process->reg[process->args.arg[1] - 1],
//							process->reg[process->args.arg[2] - 1]) : 0;
		process->carry_flag = (char) (process->reg[process->args.arg[2] - 1]
									  == 0 ? 1 : 0);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int						ft_and(t_process *process, t_player *player)
{
	char *c_byte;

	(void *)player;
	if (!process->args.error)
	{
		c_byte = c_bite_to_str(process->args.coding_byte);
		if (c_byte[0] == '0' && c_byte[1] == '1')
			process->args.arg[0] =
					process->reg[process->args.arg[0] - 1];
		if (c_byte[2] == '0' && c_byte[3] == '1')
			process->args.arg[1] =
					process->reg[process->args.arg[1] - 1];
		process->reg[process->args.arg[2] - 1] =
				process->args.arg[0] & process->args.arg[1];
		process->carry_flag = (char) (process->reg[process->args.arg[2] - 1]
									  == 0 ? 1 : 0);
		ft_memdel((void **)&c_byte);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int						ft_or(t_process *process, t_player *player)
{
	char *c_byte;

	(void *)player;
	if (!process->args.error)
	{
		c_byte = c_bite_to_str(process->args.coding_byte);
		if (c_byte[0] == '0' && c_byte[1] == '1')
			process->args.arg[0] =
					process->reg[process->args.arg[0] - 1];
		if (c_byte[2] == '0' && c_byte[3] == '1')
			process->args.arg[1] =
					process->reg[process->args.arg[1] - 1];
		process->reg[process->args.arg[2] - 1] = process->args.arg[0]
												 | process->args.arg[1];
		process->carry_flag = (char) (process->reg[process->args.arg[2] - 1]
									  == 0 ? 1 : 0);
		ft_memdel((void **)&c_byte);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int						ft_xor(t_process *process, t_player *player)
{
	char *c_byte;

	(void *)player;
	if (!process->args.error)
	{
		c_byte = c_bite_to_str(process->args.coding_byte);
		if (c_byte[0] == '0' && c_byte[1] == '1')
			process->args.arg[0] =
					process->reg[process->args.arg[0] - 1];
		if (c_byte[2] == '0' && c_byte[3] == '1')
			process->args.arg[1] =
					process->reg[process->args.arg[1] - 1];
		process->reg[process->args.arg[2] - 1] = process->args.arg[0] ^ process->args.arg[1];
		process->carry_flag = (char) (process->reg[process->args.arg[2] - 1]
									  == 0 ? 1 : 0);
		ft_memdel((void **)&c_byte);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}