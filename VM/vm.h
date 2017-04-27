/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:20:49 by ppanchen          #+#    #+#             */
/*   Updated: 2017/04/25 15:20:50 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "op.h"
#include <fcntl.h>

typedef struct	s_player
{
	char		signature[4];
	char		name[128];
	char		player_len[4];
	char		comment[2048];
	char 		noname[4];
	char		code[682];
	int 		code_len;
}				t_player;

t_player * read_player(char *file);