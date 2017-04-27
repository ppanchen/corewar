/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:31:20 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/19 20:33:47 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_funcs_types	*func_fill_types(void)
{
	t_funcs_types *newfunc;

	newfunc = malloc(sizeof(t_funcs_types) * 16);
	newfunc[0] = s_handler;
	newfunc[1] = s_handler;
	newfunc[2] = x_handler;
	newfunc[3] = di_handler;
	newfunc[4] = du_handler;
	newfunc[5] = di_handler;
	newfunc[6] = o_handler;
	newfunc[7] = ou_handler;
	newfunc[8] = u_handler;
	newfunc[9] = uu_handler;
	newfunc[10] = x_handler;
	newfunc[11] = xu_handler;
	newfunc[12] = c_handler;
	newfunc[13] = c_handler;
	newfunc[14] = per_handler;
	newfunc[15] = NULL;
	return (newfunc);
}

t_funcs_flags	*func_fill_flags(void)
{
	t_funcs_flags *newfunc;

	newfunc = malloc(sizeof(t_funcs_flags) * 6);
	newfunc[0] = hash_handler;
	newfunc[1] = plus_handler;
	newfunc[2] = minus_handler;
	newfunc[3] = zero_handler;
	newfunc[4] = space_handler;
	newfunc[5] = NULL;
	return (newfunc);
}

void			options_handler(t_format f, char **str)
{
	int				i;
	t_funcs_flags	*flag_types;
	char			*tmp;

	flag_types = func_fill_flags();
	i = -1;
	while (++i < 5)
		if (f.flags[i] == 1)
		{
			tmp = *str;
			*str = flag_types[i](str, f);
			ft_strdel(&tmp);
		}
	if (f.before_dot != 0 && f.flags[4] != 1)
	{
		tmp = *str;
		*str = space_handler(str, f);
		ft_strdel(&tmp);
	}
	free(flag_types);
}

char			*paste_arg(t_format *f, va_list *ap)
{
	t_funcs_types	*data_types;
	int				i;
	char			*str;

	i = 0;
	data_types = func_fill_types();
	f->spec == 'p' && p_handler(&f);
	while (f->spec != TYPES[i] && TYPES[i])
		i++;
	if (i == 15)
	{
		str = ft_strnew(2);
		str[0] = f->spec;
	}
	else
		str = data_types[i](*f, ap);
	str = precision_handler(&str, *f);
	options_handler(*f, &str);
	free(data_types);
	return (str);
}
/*
** for unicode
**
**int				is_uperc(t_format f)
**{
**	if (f.spec == 'S' || f.spec == 'C'
**		|| (f.spec == 's' && ft_strcmp(f.num_type, "l") == 0)
**		|| (f.spec == 'c' && ft_strcmp(f.num_type, "l") == 0))
**		return (1);
**	return (0);
**}
**
**char			*paste_arg(t_format *f, va_list *ap)
**{
**	t_funcs_types	*data_types;
**	int				i;
**	char			*str;
**
**	i = 0;
**	data_types = func_fill_types();
**	f->spec == 'p' && p_handler(&f);
**	if (is_uperc(*f) && unicodhandler(f, ap))
**		return (ft_strdup("\301"));
**	while (f->spec != TYPES[i] && TYPES[i])
**		i++;
**	if (i == 15)
**	{
**		str = ft_strnew(2);
**		str[0] = f->spec;
**	}
**	else
**		str = data_types[i](*f, ap);
**	str = precision_handler(&str, *f);
**	options_handler(*f, &str);
**	free(data_types);
**	return (str);
**}
*/
