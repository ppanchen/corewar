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
	if	(!pr->isn_empty)
	{
		pr->delay = op.delay - 1;
		pr->isn_empty = 1;
		return 0;
	}
	else if (pr->delay != 0 && pr->isn_empty)
	{
		pr->delay--;
		return (0);
	}
	else
	{
		pr->isn_empty = 0;
		return (1);
	}
}

char 					make_op(t_process *process, t_player *player)
{
	t_op		op;
	char		r;
	t_process	*start;

	op = find_op(process->op_code);
	if ((r = fill_check_pr(process, op)))
	{
		process->args = parse_op(process->pc, process->op_code);
		if (!process->args.error)
		{
			start = find_start(process);
			g_debug_flag ? print_info(process) : 0;
			action[process->op_code - 1](process, player);
			g_debug_flag ? printf("\n") : 0;
			g_graphic_flag ? mvprintw(64, 64, "Alive was said: %i",
								count_of_alives_kill(&start, 0)) : 0;
		}
	}
	return (r);
}

int						ft_live(t_process *process, t_player *player)
{
	if (!process->args.error)
	{
		if (index_exist(process->args.arg[0], player))
			g_winner = process->args.arg[0];
		process->said_alive++;
	}
	process->pc = ret_pc(process->pc, process->args.skip);
	process->op_code = 0;
	return (0);
}

int 					ft_ld(t_process *process, t_player *player)
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

int 					ft_st(t_process *process, t_player *player)
{
	unsigned char 	*str;
	int				pc;

	(void *)player;
	if (!process->args.error)
	{
		if (process->args.coding_byte == 112)
		{
			pc = ret_pc(process->pc, (process->args.arg[1] % IDX_MOD));
			str = to_little_endian(process->reg[process->args.arg[0] - 1]);
			place_on_field(str, pc);
			ft_memdel((void **) &str);
		}
		else
			process->reg[process->args.arg[1] - 1] =
					process->reg[process->args.arg[0] - 1];
	}
	process->op_code = 0;
	process->pc = ret_pc(process->pc, process->args.skip);
	return (0);
}
