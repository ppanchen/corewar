/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:45:27 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/29 17:49:50 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	j = 0;
	i = 0;
	while (dst[j])
		j++;
	if (j > size)
		return (s + size);
	while (src[i] && (j < size - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	return (s + d);
}
