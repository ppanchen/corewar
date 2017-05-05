/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 13:39:15 by ppanchen          #+#    #+#             */
/*   Updated: 2017/04/29 13:39:17 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			place_players(t_player *player)
{
	int coor[5];
	int i;
	int j;

	i = -1;
	coor[0] = 0;
	if (player[0].players == 2)
		coor[1] = 2047;
	else if (player[0].players == 3)
	{
		coor[1] = 1126;
		coor[2] = 2253;
	}
	else if (player[0].players == 4)
	{
		coor[1] = 1023;
		coor[2] = 2047;
		coor[3] = 3071;
	}
	coor[4] = 0;
	while (++i < player[0].players && (j = -1))
		while (++j < player[i].code_size)
			g_field[coor[i] + j] = player[i].code[j];
}
