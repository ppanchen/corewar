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

t_process	*find_start(t_process *process)
{
	while (process->prev)
		process = process->prev;
	return (process);
}

t_process	*shift_list(t_process *first, t_process *start)
{
	first->next = start;
	start->prev = first;
	return (first);
}