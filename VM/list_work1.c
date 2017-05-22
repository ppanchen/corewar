/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 14:15:22 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/06 14:15:23 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process		*find_start(t_process *process)
{
	if (!process)
		return (0);
	while (process->prev)
		process = process->prev;
	return (process);
}

unsigned int	count_of_alives_kill(t_process **pr, int kill_flag)
{
	unsigned int	count;
	unsigned int	cpy;
	t_process		*ret;
	t_process		*process;

	count = 0;
	process = *pr;
	ret = process;
	while (process && ret)
	{
		count += process->said_alive;
		cpy = process->said_alive;
		process->said_alive = kill_flag == 0 ? cpy : 0;
		if (cpy == 0 && kill_flag && process->new_pr != 1)
			ret = kill_process(&process);
		else
			process = process->next;
		*pr = process ? process : ret;
	}
	fill_new_pr(find_start(*pr));
	return (count);
}

void			check_process(t_process **process)
{
	static int		count_of_delta = 0;
	static int		to_die = CYCLE_TO_DIE;
	static int		count_of_cycles = 0;

	(g_graphic_flag) && mvprintw(64, 126, " CYCLE_TO_DIE: % 4d |"
	" count_of_deltas: % 3d | count_of_cycles: % 2d ", CYCLE_TO_DIE -
	CYCLE_DELTA * count_of_delta > 0 ? CYCLE_TO_DIE - CYCLE_DELTA *
	count_of_delta : 0, count_of_delta, count_of_cycles);
	if (to_die == 0)
	{
		if (count_of_alives_kill(process, 1) >= NBR_LIVE
			|| count_of_cycles == MAX_CHECKS)
		{
			count_of_delta++;
			count_of_cycles = 0;
			(g_debug_flag) && printf("Cycle to die is now %i\n",
								CYCLE_TO_DIE - CYCLE_DELTA * count_of_delta);
		}
		else
			count_of_cycles++;
		to_die = CYCLE_TO_DIE - CYCLE_DELTA * count_of_delta - 1 > 0 ?
				CYCLE_TO_DIE - CYCLE_DELTA * count_of_delta - 1 : 0;
	}
	else
		to_die--;
}

t_process		*cpy_process(t_process *process)
{
	int			i;
	t_process	*new_pr;

	new_pr = (t_process *)malloc(sizeof(t_process));
	i = -1;
	while (++i < 16)
		new_pr->reg[i] = process->reg[i];
	new_pr->args = process->args;
	new_pr->pc = process->pc;
	new_pr->carry_flag = process->carry_flag;
	new_pr->said_alive = 0;
	new_pr->op_code = 0;
	new_pr->delay = 0;
	new_pr->isn_empty = 0;
	new_pr->new_pr = 1;
	new_pr->next = 0;
	new_pr->prev = 0;
	return (new_pr);
}

t_process		*shift_list(t_process *first, t_process *start)
{
	first->next = start;
	start->prev = first;
	return (first);
}
