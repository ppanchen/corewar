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

	i = 0;
	process = fill_process(player);
	start = process;
	while(start)
	{
		int n = 0;
		while (process)
		{
			if (empty_procces(*process))
			{
				process->args = parse_op(process->pc);
				int j = -1;
				ft_printf("pr N: %02d | %04d | ", n, process->pc);
				while (++j < process->args.skip)
					ft_printf("%.2x ", g_field[process->pc + j]);
				ft_printf("\n");
				if (process->args.op_code <= 0 || process->args.op_code > 16)
					process->pc++;
			}
			if (!(process->args.op_code <= 0 || process->args.op_code > 16) &&
 					action[process->args.op_code - 1](process, player))
			{
				continue ;
			}
			if (process->next == 0)
				break ;
			process = process->next;
			n++;
		}
//		if (i == 50)
//			print_field();
		i++;
		process = find_start(process);
		check_process(&process);
		start = find_start(process);
		process = start;
	}
	print_field();
}
