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

char 			empty_procces(t_process pr)
{
	if (pr.op_code == 0 && pr.delay == 0)
		return (1);
	return (0);
}

t_args			clean_arg()
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


void			run_processes(t_player *player)
{
	t_process	*process;
	t_process	*start;
	int 		i;
	int 		flag;

	i = 0;
	flag = 0;
	process = fill_process(player);
	start = process;
	while(start)
	{
		int n = 0;
		while (process)
		{
			if (!process->isn_empty)
			{
//				process->args = parse_op(process->pc);
				process->op_code = g_field[process->pc];
//				int j = -1;
//				ft_printf("pr N: %02d | %04d | ", n, process->pc);
//				while (++j < 7)
//					ft_printf("%.2x ", g_field[process->pc + j]);
//				ft_printf("\n");
				if ((process->op_code <= 0 || process->op_code > 16)/* && !flag*/)
					process->pc = ret_pc(process->pc, 1);
			}
			if (!(process->op_code <= 0 || process->op_code > 16) &&
 					action[process->op_code - 1](process, player))
			{
//				process->op_code = g_field[process->pc];
//				if (process->op_code > 0 && process->op_code <= 16)
					continue ;
			}
			flag = 0;
			if (process->next == 0)
				break ;
			process = process->next;
			n++;
		}
		if (g_show_map_flag && g_show_map_flag == i)
			print_field();
		process = find_start(process);
		(g_graphic_flag) && print_hand(process, i);
		i++;
		check_process(&process);
		start = find_start(process);
		process = start;
	}
	ft_printf("i = %d\n", i);
//	print_field();
}
