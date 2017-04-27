/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:14:19 by ppanchen          #+#    #+#             */
/*   Updated: 2016/12/08 16:06:09 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (0);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (i == j + 1)
	{
		cpy = ft_strsub(s, 0, 0);
		return (cpy);
	}
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	cpy = ft_strsub(s, i, j - i + 1);
	return (cpy);
}
