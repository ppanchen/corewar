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

t_player	*read_player(char *file)
{
	int			fd;
	t_player	*player;


	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	player = (t_player *)malloc(sizeof(t_player));
	read(fd, &player->signature, 4);
	read(fd, &player->name, 128);
	read(fd, &player->noname, 4);
	read(fd, &player->player_len, 4);
	read(fd, &player->comment, 2048);
	read(fd, &player->noname, 4);
	player->code_len = read(fd, &player->code, 682);
	return (player);
}
