/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:50:27 by ppanchen          #+#    #+#             */
/*   Updated: 2016/12/08 17:33:07 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	int			is_neg;
	long long	ncpy;

	i = 0;
	is_neg = 0;
	ncpy = n;
	ncpy = ncpy < 0 ? -ncpy : ncpy;
	if (n < 0)
		is_neg = 1;
	str = (char *)malloc(20);
	if (!str)
		return (0);
	while (ncpy >= 10)
	{
		str[i++] = ncpy % 10 + '0';
		ncpy /= 10;
	}
	str[i] = ncpy % 10 + '0';
	if (is_neg == 1)
		str[++i] = '-';
	str[i + 1] = 0;
	return (ft_strrev(str));
}
