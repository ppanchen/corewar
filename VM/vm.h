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


#ifndef VM_H
# define VM_H
# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct	s_player
{
	unsigned char		signature[4];
	unsigned char		name[128 + 1];
	unsigned char		player_len[4];
	unsigned char		comment[2048 + 1];
	unsigned char 		noname[4];
	unsigned char		code[682 + 1];
	int 		code_len;
}				t_player;

typedef int 	(* t_action)(void);
t_action 		action[17];

int				ft_live();			//have to be realized
int				ft_ld();			//have to be realized
int				ft_st();			//have to be realized
int				ft_add();			//have to be realized
int				ft_sub();			//have to be realized
int				ft_and();			//have to be realized
int				ft_or();			//have to be realized
int				ft_xor();			//have to be realized
int				ft_zjmp();			//have to be realized
int				ft_ldi();			//have to be realized
int				ft_sti();			//have to be realized
int				ft_fork();			//have to be realized
int				ft_lld();			//have to be realized
int				ft_lldi();			//have to be realized
int				ft_lfork();			//have to be realized
int				ft_aff();			//have to be realized


t_player		*read_player(char *file);
void			place_players(t_player **player);
unsigned char 			g_field[4096];
#endif