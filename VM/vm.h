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

typedef struct			s_player
{
	unsigned int        magic;
	unsigned int        code_size;
	char                name[128 + 1];
	char                comment[2048 + 1];
	unsigned char		code[682 + 1];
	int                 players;
}                		t_player;

typedef struct			s_process
{
	int 				reg[16];
	char 				op_code;
	int 				delay;
	int 				pc;
	char				carry_flag;
/*
**	0 - if reg[n] = x, x != 0;
**	1 - if reg[n] = 0;
*/
	char				said_alive;
	int					live_count;
	struct s_process	*prev;
	struct s_process	*next;
}						t_process;

typedef struct			s_args
{
	int 				arg[3];
	char 				coding_byte;
	char 				op_code;
	int 				skip;
	char 				error;
}						t_args;

typedef int				(* t_action)(t_process **process, t_args args);
t_action 				action[17];

int						ft_live(t_process **process, t_args args);		//have to be realized
int						ft_ld(t_process **process, t_args args);		//have to be realized
int						ft_st(t_process **process, t_args args);		//have to be realized
int						ft_add(t_process **process, t_args args);		//have to be realized
int						ft_sub(t_process **process, t_args args);		//have to be realized
int						ft_and(t_process **process, t_args args);		//have to be realized
int						ft_or(t_process **process, t_args args);		//have to be realized
int						ft_xor(t_process **process, t_args args);		//have to be realized
int						ft_zjmp(t_process **process, t_args args);		//have to be realized
int						ft_ldi(t_process **process, t_args args);		//have to be realized
int						ft_sti(t_process **process, t_args args);		//have to be realized
int						ft_fork(t_process **process, t_args args);		//have to be realized
int						ft_lld(t_process **process, t_args args);		//have to be realized
int						ft_lldi(t_process **process, t_args args);		//have to be realized
int						ft_lfork(t_process **process, t_args args);		//have to be realized
int						ft_aff(t_process **process, t_args args);		//have to be realized
t_player				*read_player(char *file);
unsigned char 			g_field[4096];
char 					g_winner;
int 					indexes[4];


t_process				*fill_process(t_player *player);
void    				ft_magic(int fd, int j, t_player *champs);
void    				ft_name(int fd, int j, t_player *champs);
void    				ft_prog_size(int fd, int j, t_player *champs);
void    				ft_comment_code(int fd, int j, t_player *champs);
int   					ft_count_champs(char **mass, int sum);
void    				ft_make_player(int fd, int j, t_player *champs);
void					run_processes(t_player *player);
void					place_players(t_player *player);
t_process				*del_process(t_process **to_del);
t_args					parse_op(int pc);
t_process				*find_start(t_process *process);
t_op 					find_op(char	op_code);
void					fill_indexes(t_player player[]);



#endif