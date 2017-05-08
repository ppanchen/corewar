/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:23:17 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/08 22:23:18 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int						ft_zjmp(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		if (process->carry_flag == 1)
			process->pc = process->args.arg[0];
	}
	return (r);
}

int 					ft_lld(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		process->reg[process->args.arg[1] - 1] = process->args.arg[0];
		process->carry_flag =  (char)(process->args.arg[0] != 0 ? 1 : 0);
	}
	return (r);
}

int						ft_ldi(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		// todo
	}
	return (r);
}

