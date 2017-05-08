/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op0.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 14:21:29 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/06 14:21:30 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_op 					find_op(char	op_code)
{
	if(op_code < 1 && op_code > 16)
		return (op_tab[16]);
	return (op_tab[op_code - 1]);
}

char					fill_check_pr(t_process	*pr, t_op op)
{
	if	(pr->delay == 0 && !pr->op_code)
	{
		pr->delay = op.delay;
		pr->op_code = (char)op.op_code;
		return 0;
	}
	else if (pr->delay != 0)
	{
		pr->delay--;
		return (0);
	}
	else
		return (1);
}

int						ft_live(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		if (index_exist(process->args.arg[0], player))
			g_winner = process->args.arg[0];
		process->said_alive++;
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int 					ft_ld(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		process->reg[process->args.arg[1] - 1] = process->args.arg[0];
		process->carry_flag =  (char)(process->args.arg[0] != 0 ? 1 : 0);
	}
	return (r);
}

int 					ft_st(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;
	char 	str[5];
	int 	pc;

	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		if (process->args.op_code == 112)
		{
			pc = ret_pc(process->pc, (process->args.arg[1] % IDX_MOD));
			str = to_little_endian(process->reg[process->args.arg[0] - 1]);
			place_on_field(str, pc);
		}
		else
		{
			process->reg[process->args.arg[1] - 1] =
					process->reg[process->args.arg[0] - 1];
		}
	}
	return (r);
}
