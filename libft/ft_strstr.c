/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:03:48 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/29 14:28:15 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*str;
	char	*to_find;

	i = 0;
	if (!big || !little)
		return (0);
	str = (char *)big;
	to_find = (char *)little;
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == 0)
				return (str + i);
			j++;
		}
		i++;
	}
	if (ft_strlen(to_find) == 0)
		return (str);
	return (0);
}
