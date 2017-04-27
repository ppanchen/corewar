/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handlers(oOuUxX).c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:00:26 by ppanchen          #+#    #+#             */
/*   Updated: 2017/01/19 18:00:30 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*o_handler(t_format f, va_list *ap)
{
	long long int	i;
	char			*str;

	if (ft_strstr(f.num_type, "ll") != 0)
		i = va_arg(*ap, unsigned long long);
	else if (ft_strstr(f.num_type, "l") != 0)
		i = va_arg(*ap, unsigned long int);
	else if (ft_strstr(f.num_type, "hh") != 0)
		i = (unsigned char)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "h") != 0)
		i = (unsigned short int)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "j") != 0)
		i = va_arg(*ap, uintmax_t);
	else if (ft_strstr(f.num_type, "z") != 0)
		i = va_arg(*ap, size_t);
	else
		i = va_arg(*ap, unsigned int);
	str = ft_itoa_base_udw(i, 8);
	return (str);
}

char	*ou_handler(t_format f, va_list *ap)
{
	long long int	i;
	char			*str;

	if (ft_strstr(f.num_type, "ll") != 0)
		i = va_arg(*ap, unsigned long long);
	else if (ft_strstr(f.num_type, "l") != 0)
		i = va_arg(*ap, unsigned long int);
	else if (ft_strstr(f.num_type, "hh") != 0)
		i = va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "h") != 0)
		i = (unsigned short int)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "j") != 0)
		i = va_arg(*ap, uintmax_t);
	else if (ft_strstr(f.num_type, "z") != 0)
		i = va_arg(*ap, size_t);
	else
		i = va_arg(*ap, unsigned long int);
	str = ft_itoa_base_udw(i, 8);
	return (str);
}

char	*u_handler(t_format f, va_list *ap)
{
	unsigned long long int	i;
	char					*str;

	if (ft_strstr(f.num_type, "ll") != 0)
		i = va_arg(*ap, unsigned long long);
	else if (ft_strstr(f.num_type, "l") != 0)
		i = va_arg(*ap, unsigned long int);
	else if (ft_strstr(f.num_type, "hh") != 0)
		i = (unsigned char)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "h") != 0)
		i = (unsigned short int)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "j") != 0)
		i = va_arg(*ap, uintmax_t);
	else if (ft_strstr(f.num_type, "z") != 0)
		i = va_arg(*ap, size_t);
	else
		i = va_arg(*ap, unsigned int);
	str = ft_itoa_base_udw(i, 10);
	return (str);
}

char	*x_handler(t_format f, va_list *ap)
{
	long long int	i;
	char			*str;

	if (ft_strstr(f.num_type, "ll") != 0)
		i = va_arg(*ap, unsigned long long);
	else if (ft_strstr(f.num_type, "l") != 0)
		i = va_arg(*ap, unsigned long int);
	else if (ft_strstr(f.num_type, "hh") != 0)
		i = (unsigned char)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "h") != 0)
		i = (unsigned short int)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "j") != 0)
		i = va_arg(*ap, uintmax_t);
	else if (ft_strstr(f.num_type, "z") != 0)
		i = va_arg(*ap, size_t);
	else
		i = va_arg(*ap, unsigned int);
	str = ft_itoa_base_udw(i, 16);
	return (str);
}

char	*xu_handler(t_format f, va_list *ap)
{
	long long int	i;
	char			*str;

	if (ft_strstr(f.num_type, "ll") != 0)
		i = va_arg(*ap, unsigned long long);
	else if (ft_strstr(f.num_type, "l") != 0)
		i = va_arg(*ap, unsigned long int);
	else if (ft_strstr(f.num_type, "hh") != 0)
		i = (unsigned char)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "h") != 0)
		i = (unsigned short int)va_arg(*ap, int);
	else if (ft_strstr(f.num_type, "j") != 0)
		i = va_arg(*ap, uintmax_t);
	else if (ft_strstr(f.num_type, "z") != 0)
		i = va_arg(*ap, size_t);
	else
		i = va_arg(*ap, unsigned int);
	str = ft_itoa_base_uup(i, 16);
	return (str);
}
