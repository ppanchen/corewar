/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:20:48 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/29 13:03:18 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len2;

	if (*little == 0)
		return ((char *)big);
	len2 = ft_strlen(little);
	while (*big && len >= len2)
	{
		if (*big == *little && ft_memcmp(big, little, len2) == 0)
			return ((char *)big);
		len--;
		big++;
	}
	return (0);
}
