/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:50:36 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/23 12:52:40 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	int				l;
	unsigned char	*str;

	i = 0;
	l = (int)len;
	str = (unsigned char *)b;
	while (i < l)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
