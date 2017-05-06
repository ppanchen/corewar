/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op0.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 14:21:29 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/06 14:21:30 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_op 					find_op(char	op_code)
{
	if(op_code < 1 && op_code > 16)
		return (op_tab[16]);
	return (op_tab[op_code - 1]);
}

char					fill_check_pr(t_process	*pr, t_op op)
{
	if	(pr->delay == 0 && !pr->op_code)
	{
		pr->delay = op.delay;
		pr->op_code = (char)op.op_code;
		return 0;
	}
	else if (pr->delay != 0)
	{
		pr->delay--;
		return (0);
	}
	else
		return (1);
}

int						ft_live(t_process **process, t_args args)
{
	t_op	op;
	char 	r;

	op = find_op(args.op_code);
	if ((r = fill_check_pr(*process, op)))
	{

		//todo ft_live
		(*process)->pc += args.skip;
	}
	return (r);
}
