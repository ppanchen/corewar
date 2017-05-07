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
		while (process)
		{
//			if (empty_procces(*process))
//				process->args = parse_op(process->pc);
			process->args.arg[0] = -2;
			process->args.op_code = 1;
			action[process->args.op_code - 1](process, player);
			if (process->next == 0)
				break ;
			process = process->next;
		}
		check_process(&process);
		i++;
		start = find_start(process);
		process = start;
	}

}
