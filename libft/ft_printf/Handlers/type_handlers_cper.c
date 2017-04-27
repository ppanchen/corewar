/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handlers(cC).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:01:34 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/06 17:10:51 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*c_handler(t_format f, va_list *ap)
{
	char *str;

	(void)f;
	str = ft_strnew(2);
	str[0] = (char)va_arg(*ap, int);
	if (str[0] == 0)
		str[0] = '\302';
	return (str);
}

char	*per_handler(t_format f, va_list *ap)
{
	(void)ap;
	(void)f;
	return (ft_strdup("%"));
}

char	*precision_handler2(char **str, t_format f)
{
	char	*ret;

	if ((f.spec == 'i' || f.spec == 'd' || f.spec == 'd') &&
		ft_atoi(*str) < 0)
		ret = retstr_fill(f.after_dot - ft_strlen(*str) + 1, str, '0', 1);
	else if (f.spec != 'c')
		ret = retstr_fill(f.after_dot - ft_strlen(*str), str, '0', 0);
	else
		ret = ft_strdup(*str);
	return (ret);
}

char	*precision_handler(char **str, t_format f)
{
	char	*ret;

	if (f.after_dot == -1 || f.spec == '%')
		ret = ft_strdup(*str);
	else if (f.after_dot == 0 &&
			(ft_strcmp(*str, "0") == 0))
		ret = ft_strdup("");
	else if (f.spec == 's')
	{
		if ((int)ft_strlen(*str) > f.after_dot)
			ret = ft_strsub(*str, 0, f.after_dot);
		else
			ret = ft_strdup(*str);
	}
	else if ((int)ft_strlen(*str) < f.after_dot)
		ret = precision_handler2(str, f);
	else if (ft_strcmp(*str, "0x0") == 0 && f.after_dot == 0 && f.spec == 'p')
		ret = ft_strdup("0x");
	else
		ret = ft_strdup(*str);
	ft_strdel(str);
	return (ret);
}
