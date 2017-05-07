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

unsigned int	count_of_alives_kill(t_process **process)
{
	unsigned int 	count;
	unsigned int	tmp;
	t_process		*ret;

	count = 0;
	ret = (*process);
	while ((*process) && ret)
	{
		count += (*process)->said_alive;
		tmp = (*process)->said_alive;
		(*process)->said_alive = 0;
		if (tmp == 0)
			ret = kill_process(process);
		else
			(*process) = (*process)->next;
	}
	return (count);
}

void			check_process(t_process **process)
{
//	static int		current_cycle = 0;
	static int		count_of_delta = 0;
	static int 		to_die = CYCLE_TO_DIE;
	static int 		count_of_cycles = 0;

	if (to_die == 0)
	{
		if (count_of_alives_kill(process) > NBR_LIVE
			|| count_of_cycles == MAX_CHECKS)
		{
			count_of_delta++;
			count_of_cycles = 0;
			to_die = CYCLE_TO_DIE - CYCLE_DELTA * count_of_delta;
		}
		else
			count_of_cycles++;
	}
	else
		to_die--;
}

t_process	*shift_list(t_process *first, t_process *start)
{
	first->next = start;
	start->prev = first;
	return (first);
}