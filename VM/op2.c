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
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->op_code);
	if ((r = fill_check_pr(process, op)))
	{
		process->args = parse_op(process->pc);
		if (!process->args.error)
		{
			if (process->carry_flag == 1)                        //can be a mistake
				process->pc = ret_pc(process->pc, process->args.arg[0]);
		}
		process->op_code = 0;
	}
	return (r);
}

int						ft_ldi(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;
	char 	*c_bite;
	int 	pc;

	(void *)player;
	op = find_op(process->op_code);
	if ((r = fill_check_pr(process, op)))
	{
		process->args = parse_op(process->pc);
		if (!process->args.error)
		{
			c_bite = c_bite_to_str(process->args.coding_byte);
			if (c_bite[0] == '0' && c_bite[1] == '1')
				process->args.arg[0] = process->reg[process->args.arg[0] - 1];
			if (c_bite[2] == '0' && c_bite[3] == '1')
				process->args.arg[1] = process->reg[process->args.arg[1] - 1];
			pc = ret_pc(process->pc, (process->args.arg[0] +
									  process->args.arg[1]) % IDX_MOD);
			process->reg[process->args.arg[2] - 1] = transfer(4, pc);
			ft_memdel((void **) &c_bite);
		}
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int						ft_sti(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;
	char 	*c_bite;
	unsigned char 	*str;
	int 	pc;

	(void *)player;
	op = find_op(process->op_code);
	if ((r = fill_check_pr(process, op)))
	{
		process->args = parse_op(process->pc);
		if (!process->args.error)
		{
			c_bite = c_bite_to_str(process->args.coding_byte);
			if (c_bite[2] == '0' && c_bite[3] == '1')
				process->args.arg[1] = process->reg[process->args.arg[1] - 1];
			if (c_bite[4] == '0' && c_bite[5] == '1')
				process->args.arg[2] = process->reg[process->args.arg[2] - 1];
			pc = ret_pc(process->pc, (process->args.arg[1] +
									 process->args.arg[2]) % IDX_MOD);
			str = to_little_endian(process->reg[process->args.arg[0] - 1]);
			place_on_field(str, pc);
			ft_memdel((void **) &str);
			ft_memdel((void **) &c_bite);
		}
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int						ft_fork(t_process *process, t_player *player)
{
	t_op			op;
	char			r;
	t_process		*new_pr;

	op = find_op(process->op_code);
	if ((r = fill_check_pr(process, op)))
	{
		process->args = parse_op(process->pc);
		if (!process->args.error)
		{
			new_pr = cpy_process(process);
			new_pr->pc += new_pr->args.arg[0] % IDX_MOD;
			new_pr->op_code = g_field[new_pr->pc];
			if (new_pr->op_code <= 0 || new_pr->op_code > 16)
				new_pr->pc++;
			else
				action[new_pr->args.op_code - 1](new_pr, player);
			shift_list(new_pr, find_start(process));
		}
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

