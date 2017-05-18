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
	timeout(1);
	refresh();
}

char	is_pc(t_process *process, int pc)
{
	while (process)
	{
		if (process->pc == pc)
			return (1);
		process = process->next;
	}
	return (0);
}

int		*print_field_gr(t_process *process, unsigned char *old_field,
						int k, int **was_pc)
{
	int i;
	int j;
	int *new_pc;
	int z;

	i = -1;
	z = 0;
	new_pc = (int *)malloc((count_process(process) + 1) * sizeof(int));
	new_pc[count_process(process)] = -1;
	while (++i < 64 && (j = -1))
		while (++j < 64)
			if (is_pc(process, j + i * 64))
			{
				attron(COLOR_PAIR(ACTIVE_COLOR));
				mvprintw(i, 3 * j, "%.2x", g_field[j + i * 64]);
				new_pc[z++] = j + i * 64;
			}
			else if ((old_field[j + i * 64] != g_field[j + i * 64] ||
					find_pc_in_arr(*was_pc, j + i * 64) != -1) &&
							!attron(COLOR_PAIR(MAIN_COLOR)))
				mvprintw(i, 3 * j, "%.2x ", g_field[j + i * 64]);
	ft_memdel((void **)was_pc);
	attron(COLOR_PAIR(MAIN_COLOR));
	mvprintw(64, 0, "i = % 6d | processes = % 6d", k, count_process(process));
	return (new_pc);
}

char	print_hand(t_process *process, int i)
{
	static int				key = 0;
	static char				flag = 0;
	static unsigned char	field[4096];
	int						j;
	static int				*arr = 0;

	(arr == 0) && (print_field());
	arr = print_field_gr(process, field, i, &arr);
	if (flag == 0 || key == 31)
	{
		while (key != 32 && key != 's' && (flag = 1))
			key = getch();
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

int		print_info(t_process *process)
{
	char	*code_bite;
	int 	i;
	int 	args_len;

	args_len = op_tab[process->op_code - 1].args_len;
	code_bite = c_bite_to_str(process->args.coding_byte);
	ft_printf("P% 5d | %s ", process->process_num,
				  op_tab[process->op_code - 1].name);
	i = -1;
	while (++i < args_len && process->args.coding_byte)
	{
		if (code_bite[0 + i * 2] == '0' && code_bite[1 + i * 2] == '1')
			ft_printf("r%i", process->args.arg[i]);
		else if (code_bite[0 + i * 2] == '1' && code_bite[1 + i * 2] == '0')
			ft_printf("%%%i", process->args.arg[i]);
		else if (code_bite[0 + i * 2] == '1' && code_bite[1 + i * 2] == '1')
			ft_printf("%d", process->args.arg[i]);
		i + 1 != args_len ? ft_printf(" ") : 1;
	}
	if (!process->args.coding_byte)
		ft_printf("%d", process->args.arg[0]);
	return (1);
}
