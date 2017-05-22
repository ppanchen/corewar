/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:39:16 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/04 14:39:17 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				count_process(t_process *pr)
{
	int i;

	i = 0;
	while (pr)
	{
		i++;
		pr = pr->next;
	}
	return (i);
}

t_args			clean_arg(void)
{
	t_args args;

	args.op_code = 0;
	args.arg[0] = 0;
	args.arg[1] = 0;
	args.arg[2] = 0;
	args.coding_byte = 0;
	args.error = 0;
	args.skip = 0;
	return (args);
}

void			cycle_pr(t_process *process, t_player *player)
{
	while (process)
	{
		if (!process->isn_empty)
		{
			process->op_code = g_field[process->pc];
			if ((process->op_code <= 0 || process->op_code > 16))
				process->pc = ret_pc(process->pc, 1);
		}
		if (!(process->op_code <= 0 || process->op_code > 16) &&
			make_op(process, player))
			continue ;
		if (process->next == 0)
			break ;
		process = process->next;
	}
}

void		find_winner(t_player *player)
{
	t_player winner;
	int i;

	i = 0;
	while (i < player[0].players)
	{
		if (player[i].index == g_winner)
			winner = player[i];
		i++;
	}
	if (!g_show_map_flag)
		(!g_graphic_flag) ?
			ft_printf("Winner is player %i \"%s\"\n", winner.pl_num ?
			winner.pl_num : -winner.index, winner.name) :
			mvprintw(64, 64, "Winner is player %i \"%s\"", winner.pl_num ?
			winner.pl_num : -winner.index, winner.name);
}

void			run_processes(t_player *player)
{
	t_process	*process;
	t_process	*start;
	int			i;

	i = 0;
	process = fill_process(player);
	start = process;
	while (start)
	{
		(g_debug_flag) && printf("It is now cycle %i\n", i);
		cycle_pr(process, player);
		if (g_show_map_flag && g_show_map_flag == i && !g_graphic_flag)
			print_field();
		process = find_start(process);
		check_process(&process);
		(g_graphic_flag) && print_hand(process, i);
		i++;
		start = find_start(process);
		process = start;
	}
	find_winner(player);
}
