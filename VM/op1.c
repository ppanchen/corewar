/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:10:08 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/08 22:10:10 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int						ft_add(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		if (!process->args.error)
		{
			process->reg[process->args.arg[2]] =
					process->reg[process->args.arg[0]] +
					process->reg[process->args.arg[1]];
			process->carry_flag = (char) (process->reg[process->args.arg[2]]
										  == 0 ? 1 : 0);
		}
		process->pc += process->args.skip;
		process->op_code = 0;
 	}
	return (r);
}

int						ft_sub(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		if (!process->args.error)
		{
			process->reg[process->args.arg[2]] =
					process->reg[process->args.arg[0]] -
					process->reg[process->args.arg[1]];
			process->carry_flag = (char) (process->reg[process->args.arg[2]]
										  == 0 ? 1 : 0);
		}
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int						ft_and(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		if (!process->args.error)
		{
			process->reg[process->args.arg[2]] = process->args.arg[0] &
												 process->args.arg[1];
			process->carry_flag = (char) (process->reg[process->args.arg[2]]
										  == 0 ? 1 : 0);
		}
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int						ft_or(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		if (!process->args.error)
		{
			process->reg[process->args.arg[2]] = process->args.arg[0] |
												 process->args.arg[1];
			process->carry_flag = (char) (process->reg[process->args.arg[2]]
										  == 0 ? 1 : 0);
		}
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}

int						ft_xor(t_process *process, t_player *player)
{
	t_op	op;
	char 	r;

	(void *)player;
	op = find_op(process->args.op_code);
	if ((r = fill_check_pr(process, op)))
	{
		if (!process->args.error)
		{
			process->reg[process->args.arg[2]] = process->args.arg[0] ^
												 process->args.arg[1];
			process->carry_flag = (char) (process->reg[process->args.arg[2]]
										  == 0 ? 1 : 0);
		}
		process->pc += process->args.skip;
		process->op_code = 0;
	}
	return (r);
}