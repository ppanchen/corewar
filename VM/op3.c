/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:32:03 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/09 17:32:05 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int 					ft_lld(t_process *process, t_player *player)
{
	(void *)player;
	if (!process->args.error)
	{
		process->reg[process->args.arg[1] - 1] = process->args.arg[0];
		process->carry_flag = (char) (process->args.arg[0] == 0 ? 1 : 0);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int 					ft_lldi(t_process *process, t_player *player)
{
	char 	*c_bite;
	int 	pc;

	(void *)player;
	if (!process->args.error)
	{
		c_bite = c_bite_to_str(process->args.coding_byte);
		if (c_bite[0] == '0' && c_bite[1] == '1')
			process->args.arg[0] =
					process->reg[process->args.arg[0] - 1];
		if (c_bite[2] == '0' && c_bite[3] == '1')
			process->args.arg[1] =
					process->reg[process->args.arg[1] - 1];
		pc = process->pc + (process->args.arg[0] % IDX_MOD) +
			 (process->args.arg[1] % IDX_MOD);
		process->reg[process->args.arg[2] - 1] = transfer(4, pc);
		ft_memdel((void **) &c_bite);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int						ft_lfork(t_process *process, t_player *player)
{
	t_process		*new_pr;

	if (!process->args.error)
	{
		new_pr = cpy_process(process);
		new_pr->pc = ret_pc(new_pr->pc, (short)new_pr->args.arg[0]);
		(g_debug_flag) ? printf(" (%i)", new_pr->pc) : 0;
		new_pr->op_code = g_field[new_pr->pc];
		new_pr->process_num = ret_next_num(process);
		if (new_pr->op_code <= 0 || new_pr->op_code > 16)
			new_pr->pc++;
		else
			make_op(new_pr, player);
		shift_list(new_pr, find_start(process));
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int						ft_aff(t_process *process, t_player *player)
{
	(void *)player;
	if (!process->args.error)
	{
		ft_printf("%uc", process->reg[process->args.arg[0] - 1] % 256);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}
