/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:52:49 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/06 16:57:38 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t		ft_ustrlen(wchar_t *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

wchar_t		*ft_ustrsub(wchar_t *s, unsigned int start, size_t len)
{
	size_t	i;
	wchar_t	*retstr;

	i = 0;
	if (!s)
		return (0);
	retstr = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (!retstr)
		return (0);
	while (s[start] && i < len)
	{
		retstr[i] = s[start];
		start++;
		i++;
	}
	retstr[i] = 0;
	return (retstr);
}

wchar_t		*ft_ustrdup(const char *s1)
{
	int		i;
	wchar_t	*cpy;

	i = 0;
	cpy = (wchar_t *)malloc(sizeof(wchar_t) * (ft_strlen(s1) + 1));
	if (!cpy || !s1)
		return (0);
	while (s1[i] != 0)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

wchar_t		*ft_ustrdupu(wchar_t *s1)
{
	int		i;
	wchar_t	*cpy;

	i = 0;
	cpy = (wchar_t *)malloc(sizeof(wchar_t) * (ft_ustrlen(s1) + 1));
	if (!cpy || !s1)
		return (0);
	while (s1[i] != 0)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

wchar_t		*ft_ustrjoin(wchar_t *s1, wchar_t *s2)
{
	wchar_t	*ret;
	int		i;
	int		j;

	if (!s1)
		return (ft_ustrdupu(s2));
	if (!s2)
		return (ft_ustrdupu(s1));
	i = ft_ustrlen(s1) + ft_ustrlen(s2);
	ret = (wchar_t *)malloc(sizeof(wchar_t) * (i + 1));
	if (!ret)
		return (0);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = 0;
	return (ret);
}
