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

void			run_processes(t_player *player)
{
	t_process	*process;
	t_args		arg;
	t_process	*start;

	process = fill_process(player);
	fill_indexes(player);
	start = process;
	while(start)
	{
		while (process)
		{
			arg = parse_op(process->pc);

			action[arg.op_code - 1](&process, arg);
			process = process->next;
		}
		start = find_start(process);
		process = start;
	}


}
