/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:42:41 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/12 14:42:42 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_graphic(void)
{
	initscr();
	cbreak();
	noecho();
	start_color();
	curs_set(0);
	init_pair(MAIN_COLOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(ACTIVE_COLOR, COLOR_BLACK, COLOR_YELLOW);
	init_pair(NEW_COLOR, COLOR_BLUE, COLOR_BLACK);
	timeout(100);
	refresh();
}

char 	is_pc(t_process *process, int pc)
{
	while (process)
	{
		if (process->pc == pc)
			return (1);
		process = process->next;
	}
	return (0);
}

void	print_field_gr(t_process *process, unsigned char *old_field, int k)
{
	int i;
	int j;

	clear();
	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			if (is_pc(process, j + i * 64))
				attron(COLOR_PAIR(ACTIVE_COLOR));
			if (old_field[j + i * 64] != g_field[j + i * 64])
				attron(COLOR_PAIR(NEW_COLOR));
			printw("%.2x ", g_field[j + i * 64]);
			attron(COLOR_PAIR(MAIN_COLOR));
			j++;
		}
		attron(COLOR_PAIR(MAIN_COLOR));
		printw("\n");
		i++;
	}
	attron(COLOR_PAIR(MAIN_COLOR));
	printw("i = %d", k);
}

char 	print_hand(t_process *process, int i)
{
	static int		key = 0;
	static char		flag = 0;
	static unsigned  char 	field[4096];
	int				j;

	print_field_gr(process, field, i);
	if (flag == 0 || key == 31)
	{
		while (key != 32 && key != 's')
		{
			flag = 1;
			key = getch();
		}
		if (key == (int)'s')
		{
			flag = 0;
			key = 0;
		}
	}
	else
		key = getch() - 1;
	j = -1;
	while (++j < 4096)
		field[j] = g_field[j];
	return (0);
}
