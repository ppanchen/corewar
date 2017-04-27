/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:57:25 by ppanchen          #+#    #+#             */
/*   Updated: 2016/12/08 17:35:24 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**ret;
	int		count;

	i = 0;
	if (!s)
		return (0);
	count = ft_cwords(s, c);
	ret = (char **)malloc(sizeof(*ret) * (count + 1));
	if (!ret)
		return (0);
	while (i < count)
	{
		while (*s == c && *s != 0)
			s++;
		ret[i] = ft_strsub(s, 0, ft_strclen(s, c));
		if (!ret[i])
			return (0);
		s += ft_strclen((char *)s, c);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
