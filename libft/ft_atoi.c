/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:45:29 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/29 18:42:21 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int is_negative;
	int res;

	i = 0;
	res = 0;
	is_negative = 0;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v' ||
			nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		is_negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57 && nptr[i])
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	if (is_negative == 1)
		return (-res);
	return (res);
}
