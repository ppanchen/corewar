/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:47:43 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/01 18:36:07 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int		i;
	double	j;
	double	res;

	i = ft_atoi(str);
	str += ft_numlen(i) + 1;
	j = ft_atoi(str);
	res = j / ft_pow(10, ft_numlen(j));
	res += i;
	return (res);
}
