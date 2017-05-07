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

int ft_find_cor(char *s, int sum)
{
	int len;
	char *tmp;

	len = (int)ft_strlen(s);
	if (len >= 5)
	{
		tmp = s;
		tmp = tmp + len - 4;
		if (ft_strcmp(tmp, ".cor") == 0)
			sum++;
	}
	return (sum);
}

int   ft_count_champs(char **mass, int sum)
{
	int i;

	i = 0;
	while(mass[i])
	{
		sum = ft_find_cor(mass[i], sum);
		i++;
	}
	return (sum);
}


void    ft_make_player(int fd, int j, t_player *champs)
{
	char extra[4];

	ft_magic(fd, j, champs);
	ft_name(fd, j, champs);
	read(fd, extra, 4);
	ft_prog_size(fd, j, champs);
	ft_comment_code(fd, j, champs);
	champs[j].index = -(j + 1);
}

void    ft_comment_code(int fd, int j, t_player *champs)
{
	read(fd, champs[j].comment, 2052);
	champs[j].comment[2048] = 0;
	read(fd, champs[j].code, 682);
	champs[j].code[682] = 0;
}
