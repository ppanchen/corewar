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

unsigned int	count_of_alives_kill(t_process **pr)
{
	unsigned int 	count;
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
		process->said_alive = 0;
		if (cpy == 0)
			ret = kill_process(&process);
		else
			process = process->next;
		*pr = process ?: ret;
	}
	return (count);
}

void			check_process(t_process **process)
{
	static int		count_of_delta = 0;
	static int 		to_die = CYCLE_TO_DIE - 1;
	static int 		count_of_cycles = 0;

	if (to_die == 0)
	{
		if (count_of_alives_kill(process) > NBR_LIVE
			|| count_of_cycles == MAX_CHECKS)
		{
			count_of_delta++;
			count_of_cycles = 0;
		}
		else
			count_of_cycles++;
		to_die = CYCLE_TO_DIE - CYCLE_DELTA * count_of_delta - 1;
	}
	else
		to_die--;
}

t_process	*cpy_process(t_process *process)
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
	return (new_pr);
}

t_process	*shift_list(t_process *first, t_process *start)
{
	first->next = start;
	start->prev = first;
	return (first);
}