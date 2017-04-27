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

int 	main(int argc, char **argv)
{
	int			i;
	t_player	*player;

	//////////////////////////
	// 0xDE, 0xAD, 0xBE, 0xEF
	int x = 0xDE << 24 | 0xAD << 16 | 0xBE << 8 | 0xEF;
	x = 0xDEADBEEF;
	char *p = (char *)&x;
	printf(">>%2hhX %2hhX %2hhX %2hhX<<\n", p[0], p[1], p[2], p[3]);
	//////////////////////////

	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-n") == 0);
			//TODO grafics
		else
		{
			player = read_player(argv[i]);
			int k = -1;
			ft_printf("sign is: \n");
			while (++k < 4)
				ft_printf("%.2hhx\n", player->signature[k]);
			ft_printf("name is: \n");
			k = -1;
			while (++k < 128)
				ft_printf("%.2hhx\n", player->name[k]);
			ft_printf("len is: \n");
			k = -1;
			while (++k < 4)
				ft_printf("%.2hhx\n", player->player_len[k]);
			k = -1;
			ft_printf("comment is: \n");
			while (++k < 2048)
				ft_printf("%.2hhx\n", player->comment[k]);
			k = -1;
			ft_printf("code is: \n");
			while (++k < player->code_len)
				ft_printf("%.2hhx\n", player->code[k]);
		}
	}
	return (0);
}
