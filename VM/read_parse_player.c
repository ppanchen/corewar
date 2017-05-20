/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_parse_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:19:46 by ppanchen          #+#    #+#             */
/*   Updated: 2017/04/25 15:19:46 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int   ft_count_champs(char **mass, int sum, int argc)
{
	int i;

	i = 1;
	while(i < argc)
	{
		if (ft_strcmp(mass[i], "-g") == 0 || ft_strcmp(mass[i], "-v") == 0)
			i += 1;
		else if (ft_strcmp(mass[i], "-d") == 0 || !ft_strcmp(mass[i], "-n"))
			i += 2;
		else
		{
			i++;
			sum++;
		}
	}
	return (sum);
}


void    ft_make_player(int fd, int j, t_player *champs)
{
	char extra[4];

	ft_magic(fd, j, champs);
	ft_name(fd, j, champs);
	if (read(fd, extra, 4) < 4)
		exit(ft_printf("Error: File №%d is too small to be a champion\n", j));
	ft_prog_size(fd, j, champs);
	ft_comment_code(fd, j, champs);
	champs[j].index = -(j + 1);
	if (champs[j].code_size > CHAMP_MAX_SIZE ||
			champs[j].magic != COREWAR_EXEC_MAGIC)
		exit(ft_printf("There is some error in player №%d\n", j + 1));
}

void    ft_comment_code(int fd, int j, t_player *champs)
{
	if (read(fd, champs[j].comment, 2052) < 2052)
		exit(ft_printf("Error: File №%d is too small to be a champion\n", j));
	champs[j].comment[2048] = 0;
	read(fd, champs[j].code, 682);
	champs[j].code[682] = 0;
}
