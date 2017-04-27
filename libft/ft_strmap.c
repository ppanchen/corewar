/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:52:10 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/29 14:24:24 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
