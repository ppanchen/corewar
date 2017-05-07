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

void    ft_magic(int fd, int j, t_player *champs)
{
	int             i;
	unsigned char   mass[4];
	char            arr[4];
	void            *num;

	num = arr;
	i = 0;
	read(fd, mass, 4);
	while (i < 4)
	{
		arr[3-i] = mass[i];
		i++;
	}
	champs[j].magic = *(unsigned int*)num;
}

void    ft_name(int fd, int j, t_player *champs)
{
	read(fd, champs[j].name, 128);
	champs[j].name[128] = 0;
}

void    ft_prog_size(int fd, int j, t_player *champs)
{
	int             i;
	unsigned char   mass[4];
	char            arr[4];
	void            *num;

	num = arr;
	i = 0;
	read(fd, mass, 4);
	while (i < 4)
	{
		arr[3 - i] = mass[i];
		i++;
	}
	champs[j].code_size= *(unsigned int *)num;
}

void    ft_division(char **mass, t_player *champs)
{
	int fd;
	int i;
	int len;
	char *tmp;
	int j;

	j = -1;
	i = 0;
	while (mass[i])
	{
		len = (int)ft_strlen(mass[i]);
		if (len >= 5)
		{
			tmp = mass[i];
			tmp = tmp + len - 4;
			if (ft_strcmp(tmp, ".cor") == 0)
			{
				j = j + 1;
				fd = open(mass[i], O_RDONLY);
				ft_make_player(fd, j, champs);
			}
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int         sum;
	int         i;
	t_player    *champs;
	int 		k = -1;			//for debug

	i = 0;
	if (argc >= 2)
		sum = ft_count_champs(argv, 0);
	champs = (t_player*)malloc(sizeof(t_player) * sum);
	champs[0].players = sum;
	if (argc >= 2)
		ft_division(argv, champs);
	place_players(champs);
	run_processes(champs);
//	while (++k < 4096)
//		ft_printf("%.2x ", g_field[k]);
}