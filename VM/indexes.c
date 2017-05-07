/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 16:25:50 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/06 16:25:51 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char 					index_exist(int index, t_player *player)
{
	int 	i;

	i = -1;
	while (++i < player[0].players)
		if (player[i].index == index)
			return (1);
	return (0);
}