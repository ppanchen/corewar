/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:43:16 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/22 14:43:23 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		find_pc_in_arr(int *arr, int val)
{
	int i;

	i = -1;
	if (!arr)
		return (-1);
	while (arr[++i] != -1)
		if (arr[i] == val)
			return (i);
	return (-1);
}

int		fill_new_pr(t_process *pr)
{
	if (!pr)
		return (0);
	while (pr)
	{
		pr->new_pr = 0;
		pr = pr->next;
	}
	return (0);
}
