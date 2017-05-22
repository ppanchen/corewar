/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:53:42 by ppanchen          #+#    #+#             */
/*   Updated: 2017/04/24 13:53:43 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vm.h"

void		ft_magic(int fd, int j, t_player *champs)
{
	int				i;
	unsigned char	mass[4];
	char			arr[4];
	void			*num;

	num = arr;
	i = 0;
	if (read(fd, mass, 4) < 4)
		exit(ft_printf("Error: File №%d is too small to be a champion\n", j));
	while (i < 4)
	{
		arr[3 - i] = mass[i];
		i++;
	}
	champs[j].magic = *(unsigned int*)num;
}

void		ft_name(int fd, int j, t_player *champs)
{
	if (read(fd, champs[j].name, 128) < 128)
		exit(ft_printf("Error: File №%d "
				"is too small to be a champion\n", j));
	champs[j].name[128] = 0;
}

void		ft_prog_size(int fd, int j, t_player *champs)
{
	int				i;
	unsigned char	mass[4];
	char			arr[4];
	void			*num;

	num = arr;
	i = 0;
	if (read(fd, mass, 4) < 4)
		exit(ft_printf("Error: File №%d is too small to be a champion\n", j));
	while (i < 4)
	{
		arr[3 - i] = mass[i];
		i++;
	}
	champs[j].code_size = *(unsigned int *)num;
}

void		ft_division(char **mass, t_player *champs)
{
	int fd;
	int i;
	int j;
	int num;

	j = -1;
	i = 0;
	while (mass[++i] && !(num = 0))
		if (ft_strcmp(mass[i], "-g") != 0 && ft_strcmp(mass[i], "-d") != 0
			&& ft_strcmp(mass[i], "-v") != 0)
		{
			if (ft_strcmp(mass[i], "-n") == 0)
				((num = ft_atoi(mass[++i]))) ? i++ : show_usage();
			fd = open(mass[i], O_RDONLY);
			if (fd == -1)
			{
				perror(mass[i]);
				exit(-1);
			}
			ft_make_player(fd, ++j, champs);
			champs[j].pl_num = num ? num : 0;
		}
		else if (ft_strcmp(mass[i], "-d") == 0)
			i += 1;
}

int			main(int argc, char **argv)
{
	t_player	*player;
	char 		c;

	player = 0;
	find_flag(argv, argc);
	player = fill_player(argv, argc);
	if (g_graphic_flag)
		init_graphic();
	place_players(player);
	run_processes(player);
	if (g_graphic_flag)
	{
		c = 0;
		while (c != '\n')
			c = (char)getch();
		endwin();
	}
	free(player);
	return (0);
}
