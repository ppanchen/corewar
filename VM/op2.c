/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:23:17 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/08 22:23:18 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int						ft_zjmp(t_process *process, t_player *player)
{
	(void *)player;
	if (!process->args.error)
	{
		if (process->carry_flag == 1)
			process->pc = ret_pc(process->pc, (short)process->args.arg[0]);
		else
			process->pc = ret_pc(process->pc, process->args.skip);
		if (g_debug_flag == 1)
			(process->carry_flag == 1) ? printf(" OK") : printf(" FAILED");
	}
	process->op_code = 0;
	return (0);
}

int						ft_ldi(t_process *process, t_player *player)
{
	char 	*c_bite;
	int 	pc;

	(void *)player;
	if (!process->args.error)
	{
		c_bite = c_bite_to_str(process->args.coding_byte);
		if (c_bite[0] == '0' && c_bite[1] == '1')
			process->args.arg[0] = process->reg[process->args.arg[0] - 1];
		if (c_bite[2] == '0' && c_bite[3] == '1')
			process->args.arg[1] = process->reg[process->args.arg[1] - 1];
		pc = ret_pc(process->pc, (process->args.arg[0] +
								  process->args.arg[1]) % IDX_MOD);
		(g_debug_flag) ? printf("\n       | -> load from %i + %i = %i "
										   "(with pc and mod %i)",
								process->args.arg[0], process->args.arg[1],
								   process->args.arg[0] + process->args.arg[1], pc) : 0;
		process->reg[process->args.arg[2] - 1] = transfer(4, pc);
		ft_memdel((void **) &c_bite);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int						ft_sti(t_process *process, t_player *player)
{
	char 	*c_bite;
	unsigned char 	*str;
	int 	pc;

	(void *)player;
	if (!process->args.error)
	{
		c_bite = c_bite_to_str(process->args.coding_byte);
		if (c_bite[2] == '0' && c_bite[3] == '1')
			process->args.arg[1] = process->reg[process->args.arg[1] - 1];
		if (c_bite[4] == '0' && c_bite[5] == '1')
			process->args.arg[2] = process->reg[process->args.arg[2] - 1];
		pc = ret_pc(process->pc, (process->args.arg[1] +
								  process->args.arg[2]) % IDX_MOD);
		(g_debug_flag) ? printf("\n       | -> store to %i + %i = %i "
						"(with pc and mod %i)", process->args.arg[1], process->args.arg[2],
							process->args.arg[1] + process->args.arg[2], pc) : 0;
		str = to_little_endian(process->reg[process->args.arg[0] - 1]);
		place_on_field(str, pc);
		ft_memdel((void **) &str);
		ft_memdel((void **) &c_bite);
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int 					ret_next_num(t_process *process)
{
	int max;

	max = 1;
	process = find_start(process);
	while (process->next)
	{
		if (process->process_num > max)
			max = process->process_num;
		process = process->next;
	}
	return (max + 1);
}

int						ft_fork(t_process *process, t_player *player)
{
	t_process		*new_pr;

	if (!process->args.error)
	{
		new_pr = cpy_process(process);
		new_pr->pc = ret_pc(new_pr->pc, (short)new_pr->args.arg[0] % IDX_MOD);
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

