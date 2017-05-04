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

typedef int 	(* t_action)(void);

typedef struct			s_player
{
	unsigned int        magic;
	unsigned int        code_size;
	char                name[128 + 1];
	char                comment[2048 + 1];
	char                code[682 + 1];
	int                 players;
}                		t_player;

typedef struct			s_process
{
	int 				reg[16];
	int 				op_code;
	int 				delay;
	int 				pc;
	int 				carry_flag;
/*
**	0 - if reg[n] = x, x != 0;
**	1 - if reg[n] = 0;
*/
	int					said_alive;
	int					live_count;
	struct s_process	*next;
}						t_process;

t_action 				action[17];

int						ft_live();			//have to be realized
int						ft_ld();			//have to be realized
int						ft_st();			//have to be realized
int						ft_add();			//have to be realized
int						ft_sub();			//have to be realized
int						ft_and();			//have to be realized
int						ft_or();			//have to be realized
int						ft_xor();			//have to be realized
int						ft_zjmp();			//have to be realized
int						ft_ldi();			//have to be realized
int						ft_sti();			//have to be realized
int						ft_fork();			//have to be realized
int						ft_lld();			//have to be realized
int						ft_lldi();			//have to be realized
int						ft_lfork();			//have to be realized
int						ft_aff();			//have to be realized
t_player				*read_player(char *file);
void					place_players(t_player *player);
unsigned char 			g_field[4096];
void					run_processes(t_player *player);
t_process				*fill_process(t_player *player);
void    ft_magic(int fd, int j, t_player *champs);
void    ft_name(int fd, int j, t_player *champs);
void    ft_prog_size(int fd, int j, t_player *champs);
void    ft_comment_code(int fd, int j, t_player *champs);
int   	ft_count_champs(char **mass, int sum);
void    ft_make_player(int fd, int j, t_player *champs);

#endif