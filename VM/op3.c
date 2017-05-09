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
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		process->reg[process->args.arg[1] - 1] = process->args.arg[0];
		process->carry_flag =  (char)(process->args.arg[0] != 0 ? 1 : 0);
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int 					ft_lldi(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;
	char 	*c_bite;
	int 	pc;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		c_bite = c_bite_to_str(process->args.coding_byte);
		if (c_bite[0] == '0' && c_bite[1] == '1')
			process->args.arg[0] =
					(unsigned int)process->reg[process->args.arg[0] - 1];
		if (c_bite[2] == '0' && c_bite[3] == '1')
			process->args.arg[1] =
					(unsigned int)process->reg[process->args.arg[1] - 1];
		pc = process->pc + (process->args.arg[0] % IDX_MOD) +
			 (process->args.arg[1] % IDX_MOD);
		process->reg[process->args.arg[2] - 1] = transfer(4, pc);
		ft_memdel((void **)&c_bite);
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int						ft_lfork(t_process *process, t_player *player)
{
	t_op			op;
	char			r;
	t_process		*new_pr;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		new_pr = cpy_process(process);
		new_pr->pc += new_pr->args.arg[0];
		shift_list(new_pr, find_start(process));
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int						ft_aff(t_process *process, t_player *player)
{
	t_op			op;
	char			r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		ft_printf("%uc", process->reg[process->args.arg[0] - 1] % 256);
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}
