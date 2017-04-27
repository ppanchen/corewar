/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_paste.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 12:32:44 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/04 12:32:45 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_wchar_t	*save_args(wchar_t *str, int size)
{
	static	t_wchar_t	*args = NULL;
	t_wchar_t			*new;

	if (str == 0)
		return (args);
	if (!args)
	{
		args = (t_wchar_t *)malloc(sizeof(t_wchar_t));
		args->str = str;
		args->len = size;
		args->next = NULL;
	}
	else
	{
		new = args;
		while (new->next)
			new = new->next;
		new->next = (t_wchar_t *)malloc(sizeof(t_wchar_t));
		new = new->next;
		new->str = str;
		new->len = size;
		new->next = NULL;
	}
	return (args);
}

int			wcharpaste(void)
{
	static	int		i = 0;
	t_wchar_t		*args;
	int				j;
	int				ret;
	int				t;

	ret = 0;
	args = save_args(NULL, 0);
	j = 0;
	while (j++ != i)
		args = args->next;
	j = -1;
	while (args->str[++j] != '\0' && (args->len > 0 || args->len == -1))
		if (args->str[j] == '\302')
			ret += ft_putchar('\0');
		else
		{
			t = ft_putchar_fd(args->str[j], 1, args->len);
			(args->len != -1) && (args->len -= t);
			ret += t;
		}
	i++;
	return (ret);
}

wchar_t		*uretstr_fill(int i, wchar_t *str, int rev, int *size)
{
	char	*tmp;
	wchar_t *ret;
	wchar_t	*t;

	tmp = ft_strnew(i--);
	while (i + 1)
		tmp[i--] = ' ';
	ret = ft_ustrdup(tmp);
	ft_strdel(&tmp);
	t = ret;
	(*size != -1) && (*size += ft_ustrlen(ret));
	ret = rev == 0 ? ft_ustrjoin(ret, str) : ft_ustrjoin(str, ret);
	free(t);
	return (ret);
}

wchar_t		*uretstr_fill_zero(int i, wchar_t *str, int *size)
{
	char	*tmp;
	wchar_t *ret;
	wchar_t *t;

	tmp = ft_strnew(i--);
	while (i + 1)
		tmp[i--] = '0';
	ret = ft_ustrdup(tmp);
	ft_strdel(&tmp);
	t = ret;
	(*size != -1) && (*size += ft_ustrlen(ret));
	ret = ft_ustrjoin(ret, str);
	free(t);
	return (ret);
}
