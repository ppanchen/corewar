/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:20:56 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/06 17:08:00 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char				*hash_handler(char **str, t_format f)
{
	char	*retstr;
	int		zero;
	int		fl;

	fl = 0;
	zero = (ft_strcmp(*str, "0") == 0 || ft_strcmp(*str, "") == 0) ? 0 : 1;
	if (f.flags[3] == 1 && (ft_strcmp(zero_handler(str, f), *str) != 0))
	{
		*str = zero_handler(str, f);
		fl = 1;
	}
	if (f.after_dot == (int)ft_strlen(*str) && (f.spec == 'o' || f.spec == 'O'))
		fl = 1;
	if ((f.spec == 'x' && zero != 0) || f.spec == 'p')
		retstr = fl == 1 ? ft_strjoin("0x", *str + 2) : ft_strjoin("0x", *str);
	else if (f.spec == 'X' && zero != 0)
		retstr = fl == 1 ? ft_strjoin("0X", *str + 2) : ft_strjoin("0X", *str);
	else if ((f.spec == 'o' || f.spec == 'O') && zero != 0)
		retstr = fl == 1 ? ft_strjoin("0", *str + 1) : ft_strjoin("0", *str);
	else if ((f.spec == 'o' || f.spec == 'O') && zero == 0)
		retstr = ft_strdup("0");
	else
		retstr = ft_strdup(*str);
	return (retstr);
}

char				*plus_handler(char **str, t_format f)
{
	char	*retstr;

	if (f.spec == 'i' || f.spec == 'd' || f.spec == 'D')
		retstr = ft_atoi(*str) >= 0 ? ft_strjoin("+", *str) : ft_strdup(*str);
	else
		retstr = ft_strdup(*str);
	return (retstr);
}

char				*minus_handler(char **str, t_format f)
{
	char	*retstr;
	int		i;
	char	*tmp;

	if (f.before_dot < (int)ft_strlen(*str))
		retstr = ft_strdup(*str);
	else if (f.before_dot > (int)ft_strlen(*str))
	{
		i = f.before_dot - ft_strlen(*str);
		retstr = ft_strnew(i);
		while (--i >= 0)
			retstr[i] = ' ';
		tmp = retstr;
		retstr = ft_strjoin(*str, retstr);
		ft_strdel(&tmp);
	}
	else
		retstr = ft_strdup(*str);
	return (retstr);
}

char				*space_handler(char **str, t_format f)
{
	char	*retstr;
	int		i;
	char	*tmp;

	if ((f.spec == 'i' || f.spec == 'd' ||
			f.spec == 'D') &&
			(f.before_dot == 0 && ft_atoi(*str) < 0))
		retstr = ft_strdup(*str);
	else if (f.flags[4] == 1 && ft_atoi(*str) != 0 && f.flags[1] == 0 &&
			(f.spec == 'i' || f.spec == 'd' || f.spec == 'D') &&
			((f.before_dot <= f.after_dot || f.before_dot == 0)))
		retstr = ft_strjoin(" ", *str);
	else if (f.before_dot > (int)ft_strlen(*str))
	{
		i = f.before_dot - ft_strlen(*str);
		retstr = ft_strnew(i);
		while (--i >= 0)
			retstr[i] = ' ';
		tmp = retstr;
		retstr = ft_strjoin(retstr, *str);
		ft_strdel(&tmp);
	}
	else
		retstr = ft_strdup(*str);
	return (retstr);
}
