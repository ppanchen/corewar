/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:09:03 by ppanchen          #+#    #+#             */
/*   Updated: 2017/01/22 19:16:03 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** for unicode
**
**int			write_x(char *str)
**{
**	int i;
**	int ret;
**
**	i = 0;
**	ret = 0;
**	while (str[i])
**	{
**		if (str[i] == '\302')
**			ret += ft_putchar(0);
**		else if (str[i] == '\301')
**			ret += wcharpaste();
**		else
**			ret += write(1, &str[i], 1);
**		i++;
**	}
**	return (ret);
**}
*/

int			write_x(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '\302')
			ret += ft_putchar(0);
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	return (ret);
}

int			isnt_valid(char str)
{
	if (ft_strchr(FLAGS, str) != 0 || str == '.' ||
		ft_isdigit(str) != 0 || ft_strchr(NUM_TYPES, str) != 0)
		return (1);
	return (0);
}

char		**parse_str(char *str)
{
	int		i;
	int		j;
	char	**vrs;

	i = 0;
	j = 0;
	while (str[j])
		(str[j++] == '%') && (i++);
	vrs = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (*str)
		if (*str == '%' && (j = 1))
		{
			while (isnt_valid(str[j]))
				j++;
			(ft_strchr(TYPES, str[j]) || str[j] == '%') && (j++);
			while (str[j] != '%' && str[j] != 0)
				j++;
			vrs[i++] = ft_strsub(str, 0, j);
			str += j;
		}
		else
			str++;
	vrs[i] = 0;
	return (vrs);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	**str;
	int		len;
	char	*retstr;
	char	*tmp;

	if (ft_strcmp(format, "%") == 0)
		return (0);
	str = parse_str((char *)format);
	len = ft_strclen((char *)format, '%');
	retstr = ft_strsub(format, 0, len);
	va_start(ap, format);
	len = -1;
	while (str[++len])
	{
		tmp = ft_checker(str[len], &ap);
		retstr = ft_strjoin_free(&retstr, &tmp);
	}
	len = -1;
	while (str[++len])
		ft_strdel(&str[len]);
	free(str);
	len = write_x(retstr);
	ft_strdel(&retstr);
	return (len);
}
