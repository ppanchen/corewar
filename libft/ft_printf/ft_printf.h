/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:07:41 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/06 17:02:27 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "../libft.h"
# include "limits.h"
# define TYPES "sSpdDioOuUxXcC%"
# define FLAGS "#+-0 "
# define NUM_TYPES "hh h l ll j z"

typedef struct			s_format
{
	int					flags[5];
	char				*num_type;
	int					before_dot;
	int					after_dot;
	char				spec;
}						t_format;

typedef struct			s_wchar_t
{
	wchar_t				*str;
	int					len;
	struct s_wchar_t	*next;
}						t_wchar_t;

typedef	char			*(*t_funcs_types)(t_format f, va_list *ap);
typedef	char			*(*t_funcs_flags)(char **str, t_format f);
int						ft_printf(const char *format, ...);
int						write_x(char *str);
char					*ft_checker(char *str, va_list *ap);
char					*paste_arg(t_format *f, va_list *ap);
char					*s_handler(t_format f, va_list *ap);
int						p_handler(t_format **f);
char					*di_handler(t_format f, va_list *ap);
char					*du_handler(t_format f, va_list *ap);
char					*o_handler(t_format f, va_list *ap);
char					*ou_handler(t_format f, va_list *ap);
char					*u_handler(t_format f, va_list *ap);
char					*uu_handler(t_format f, va_list *ap);
char					*x_handler(t_format f, va_list *ap);
char					*xu_handler(t_format f, va_list *ap);
char					*c_handler(t_format f, va_list *ap);
char					*per_handler(t_format f, va_list *ap);
char					*hash_handler(char **str, t_format f);
char					*zero_handler(char **str, t_format f);
char					*plus_handler(char **str, t_format f);
char					*minus_handler(char **str, t_format f);
char					*space_handler(char **str, t_format f);
char					*precision_handler(char **str, t_format f);
int						unicodhandler(t_format *f, va_list *ap);
t_wchar_t				*save_args(wchar_t *str, int size);
int						wcharpaste();
size_t					ft_ustrlen(wchar_t *s);
wchar_t					*ft_ustrsub(wchar_t *s, unsigned int start, size_t len);
wchar_t					*ft_ustrdup(const char *s1);
wchar_t					*ft_ustrjoin(wchar_t *s1, wchar_t *s2);
wchar_t					*ft_ustrdupu(wchar_t *s1);
char					*retstr_fill(int i, char **str, char c, int znak);
int						isnt_valid(char str);
wchar_t					*uretstr_fill(int i, wchar_t *str, int rev, int *size);
wchar_t					*uretstr_fill_zero(int i, wchar_t *str, int *size);
#endif
