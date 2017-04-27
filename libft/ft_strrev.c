/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:18:23 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/19 20:31:54 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = ft_strlen(str) - 1;
	j = 0;
	while (j < i)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		j++;
		i--;
	}
	return (str);
}
