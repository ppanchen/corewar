/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handlers(sSpdDi).c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:55:50 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/06 17:13:12 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*s_handler(t_format f, va_list *ap)
{
	char *str;

	(void)f;
	str = va_arg(*ap, char *);
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

int		p_handler(t_format **f)
{
	char *tmp;

	(*f)->flags[0] = 1;
	tmp = (*f)->num_type;
	(*f)->num_type = ft_strdup("l");
	ft_strdel(&tmp);
	return (0);
}

char	*di_handler(t_format f, va_list *ap)
{
	long long int	i;
	char			*str;

	if (ft_strstr(f.num_type, "j") != 0)
		i = va_arg(*ap, intmax_t);
	else if (ft_strstr(f.num_type, "z") != 0)
		i = va_arg(*ap, size_t);
	else if (ft_strstr(f.num_type, "ll") != 0)
		i = va_arg(*ap, long long);
	else if (ft_strstr(f.num_type, "l") != 0)
		i = va_arg(*ap, long int);
	else if (ft_strstr(f.num_type, "hh") != 0)
		i = (char)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "h") != 0)
		i = (short int)va_arg(*ap, int);
	else
		i = va_arg(*ap, int);
	str = ft_itoa_base_dw(i, 10);
	return (str);
}

char	*du_handler(t_format f, va_list *ap)
{
	long long int	i;
	char			*str;

	(void)f;
	i = va_arg(*ap, long long);
	str = ft_itoa_base_dw(i, 10);
	return (str);
}

char	*uu_handler(t_format f, va_list *ap)
{
	unsigned long long int	i;
	char					*str;

	(void)f;
	i = va_arg(*ap, unsigned long int);
	str = ft_itoa_base_udw(i, 10);
	return (str);
}
