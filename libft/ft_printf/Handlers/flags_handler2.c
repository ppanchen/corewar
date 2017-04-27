/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 13:31:41 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/06 17:14:59 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char				*retstr_fill(int i, char **str, char c, int znak)
{
	char	*retstr;
	char	*tmp;

	retstr = ft_strnew(i + 1);
	while (--i >= 0)
		retstr[i] = c;
	retstr[0] = znak == 2 ? ' ' : c;
	tmp = retstr;
	retstr = znak == 1 ? ft_strjoin(retstr, *str + 1) :\
	ft_strjoin(retstr, *str);
	ft_strdel(&tmp);
	if (znak == 1)
	{
		tmp = retstr;
		retstr = ft_atoi(*str) < 0 ? ft_strjoin("-", retstr) : \
		ft_strjoin("+", retstr);
		ft_strdel(&tmp);
	}
	return (retstr);
}

char				*zero_handler2(char **str, t_format f)
{
	char	*retstr;

	if (f.before_dot > (int)ft_strlen(*str) && f.after_dot != -1)
	{
		if ((f.spec == 'i' || f.spec == 'd' || f.spec == 'd') &&
			(ft_atoi(*str) < 0 || f.flags[1] == 1))
			retstr = retstr_fill(f.after_dot - ft_strlen(*str), str, '0', 1);
		else if (f.after_dot > (int)ft_strlen(*str))
			retstr = retstr_fill(f.after_dot - ft_strlen(*str), str, '0', 0);
		else if (f.after_dot <= (int)ft_strlen(*str) && f.spec == 's')
			retstr = retstr_fill(f.before_dot - ft_strlen(*str), str, '0', 0);
		else
			retstr = ft_strdup(*str);
	}
	else
		retstr = ft_strdup(*str);
	return (retstr);
}

char				*zero_handler(char **str, t_format f)
{
	char	*rstr;

	if (f.flags[2] == 1)
		rstr = ft_strdup(*str);
	else if (f.before_dot < (int)ft_strlen(*str))
		rstr = ft_strdup(*str);
	else if (f.before_dot > (int)ft_strlen(*str) && (f.after_dot == -1 ||
			f.spec == 'c' || f.spec == '%' || !ft_strchr(TYPES, f.spec)))
	{
		if ((f.spec == 'i' || f.spec == 'd' || f.spec == 'd') &&
			(ft_atoi(*str) < 0 || f.flags[1] == 1))
			rstr = retstr_fill(f.before_dot - ft_strlen(*str), str, '0', 1);
		else
		{
			if (f.flags[4] == 1)
				rstr = retstr_fill(f.before_dot - ft_strlen(*str), str, '0', 2);
			else
				rstr = retstr_fill(f.before_dot - ft_strlen(*str), str, '0', 0);
		}
	}
	else
		rstr = zero_handler2(str, f);
	return (rstr);
}
