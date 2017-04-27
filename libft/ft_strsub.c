/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:53:11 by ppanchen          #+#    #+#             */
/*   Updated: 2016/12/06 13:58:14 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*retstr;

	i = 0;
	if (!s)
		return (0);
	retstr = (char *)malloc(len + 1);
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
