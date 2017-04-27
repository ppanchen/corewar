/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:03:55 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/06 16:50:20 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BIT_7 127
#define BIT_11 2047
#define BIT_16 65535
#define BIT_21 2097151
#define BIT_26 67108863
#define BIT31 2147483647

static int		ft_putchar_fd4(const uint32_t s, char *rt, int size, int *ct)
{
	int		flag;

	flag = 0;
	if (s <= BIT_26 || size == 5)
	{
		rt[0] = ((s & 50331648) >> 24) | 248;
		rt[1] = ((s & 16515072) >> 18) | 128;
		rt[2] = ((s & 258048) >> 12) | 128;
		rt[3] = ((s & 4032) >> 6) | 128;
		rt[4] = (s & 63) | 128;
		(s > BIT_26) && (flag = 1);
		*ct = 5;
	}
	else
	{
		rt[0] = ((s & 1073741824) >> 30) | 252;
		rt[1] = ((s & 1056964608) >> 24) | 128;
		rt[2] = ((s & 16515072) >> 18) | 128;
		rt[3] = ((s & 258048) >> 12) | 128;
		rt[4] = ((s & 4032) >> 6) | 128;
		rt[5] = (s & 63) | 128;
		*ct = 6;
	}
	return (flag);
}

static int		ft_putchar_fd3(const uint32_t s, char *rt, int size, int *ct)
{
	int		flag;

	flag = 0;
	if (s <= BIT_21 || size == 4)
	{
		rt[0] = ((s & 1835008) >> 18) | 240;
		rt[1] = ((s & 258048) >> 12) | 128;
		rt[2] = ((s & 4032) >> 6) | 128;
		rt[3] = (s & 63) | 128;
		(s > BIT_21) && (flag = 1);
		*ct = 4;
	}
	else
		flag = ft_putchar_fd4(s, rt, size, ct);
	return (flag);
}

static int		ft_putchar_fd2(const uint32_t s, char *rt, int size, int *ct)
{
	int		flag;

	flag = 0;
	if (s <= BIT_11 || size == 2)
	{
		rt[0] = ((s & 1984) >> 6) | 192;
		rt[1] = (s & 63) | 128;
		(s > BIT_11) && (flag = 1);
		*ct = 2;
	}
	else if (s <= BIT_16 || size == 3)
	{
		rt[0] = ((s & 61440) >> 12) | 224;
		rt[1] = ((s & 4032) >> 6) | 128;
		rt[2] = (s & 63) | 128;
		(s > BIT_16) && (flag = 1);
		*ct = 3;
	}
	else
		flag = ft_putchar_fd3(s, rt, size, ct);
	return (flag);
}

size_t			ft_putchar_fd(const uint32_t s, const int fd, int size)
{
	char		*rt;
	int			ct;
	int			flag;

	rt = ft_strnew(6);
	ct = 0;
	flag = 0;
	if (s <= BIT_7 || size == 1)
	{
		rt[0] = s;
		(s > BIT_7) && (flag = 1);
		ct = 1;
	}
	else
		flag = ft_putchar_fd2(s, rt, size, &ct);
	if (flag || size == 0)
		ct = 0;
	else if (fd != -2)
		ct = write(fd, rt, sizeof(char)) + write(fd, &rt[1], ft_strlen(&rt[1]));
	ft_strdel(&rt);
	return (ct);
}
