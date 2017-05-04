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

//void			place_players(t_player **player)
//{
//	int coor[5];
//	int i;
//	int j;
//
//	i = -1;
//	coor[0] = 0;
//	if (ft_arrsize(player) == 2)
//		coor[1] = 2047;
//	else if (ft_arrsize(player) == 3)
//	{
//		coor[1] = 1126;
//		coor[2] = 2253;
//	}
//	else if (ft_arrsize(player) == 4)
//	{
//		coor[1] = 1023;
//		coor[2] = 2047;
//		coor[3] = 3071;
//	}
//	coor[4] = 0;
//	while (player[++i] && (j = -1))
//		while (++j < player[i]->code_len)
//			g_field[coor[i] + j] = player[i]->code[j];
//}
