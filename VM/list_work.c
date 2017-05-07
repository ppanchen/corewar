/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:35:05 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/04 16:35:06 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process		*fill_process2(t_process *start)
{
	t_process	*second;

	second = (t_process *)malloc(sizeof(t_process));
	ft_bzero(second, sizeof(t_process));
	second->reg[0] = -2;
	second->pc = 2047;
	second->prev = start;
	start->next = second;
	return (start);
}

t_process		*fill_process3(t_process *start)
{
	t_process	*second;
	t_process	*third;

	second = (t_process *)malloc(sizeof(t_process));
	ft_bzero(second, sizeof(t_process));
	second->reg[0] = -2;
	second->pc = 1126;
	second->prev = start;
	start->next = second;
	third = (t_process *)malloc(sizeof(t_process));
	ft_bzero(third, sizeof(t_process));
	third->reg[0] = -3;
	third->pc = 2253;
	third->prev = second;
	second->next = third;
	return (start);
}

t_process		*fill_process4(t_process *start)
{
	t_process	*second;
	t_process	*third;
	t_process	*fourth;

	second = (t_process *)malloc(sizeof(t_process));
	ft_bzero(second, sizeof(t_process));
	second->reg[0] = -2;
	second->pc = 1023;
	second->prev = start;
	start->next = second;
	third = (t_process *)malloc(sizeof(t_process));
	ft_bzero(third, sizeof(t_process));
	third->reg[0] = -3;
	third->pc = 2047;
	third->prev = second;
	second->next = third;
	fourth = (t_process *)malloc(sizeof(t_process));
	ft_bzero(fourth, sizeof(t_process));
	fourth->reg[0] = -4;
	fourth->pc = 3071;
	fourth->prev = third;
	third->next = fourth;
	return (start);
}

t_process		*fill_process(t_player *player)
{
	t_process	*pr;

	pr = (t_process *)malloc(sizeof(t_process));
	ft_bzero(pr, sizeof(t_process));
	pr->reg[0] = -1;

	if (player[0].players == 2)
		pr = fill_process2(pr);
	else if (player[0].players == 3)
		pr = fill_process3(pr);
	else if (player[0].players == 4)
		pr = fill_process4(pr);
	return (pr);
}

t_process		*kill_process(t_process **to_del)
{
	t_process	*tmp;
	t_process	*ret;

	if ((*to_del)->next)
		tmp = (*to_del)->next;
	else
		tmp = (*to_del)->prev;
	ret = (*to_del)->next;
	if ((*to_del)->next)
		(*to_del)->next->prev = (*to_del)->prev;
	if ((*to_del)->prev)
		(*to_del)->prev->next = (*to_del)->next;
	ft_memdel((void **)to_del);
	(*to_del) = tmp;
	return (ret);
}