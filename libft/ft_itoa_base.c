/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:32:34 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/06 17:04:43 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base_dw(long long n, int base)
{
	int					i;
	char				*str;
	int					is_neg;
	unsigned long long	ncpy;
	int					tmp;

	i = 0;
	is_neg = 0;
	(n < 0) && (is_neg = 1);
	ncpy = M(n);
	str = (char *)malloc(50);
	if (!str)
		return (0);
	while (ncpy >= (unsigned long long)base)
	{
		tmp = ncpy % base;
		str[i++] = tmp >= 10 ? 'a' + tmp - 10 : tmp + '0';
		ncpy /= base;
	}
	tmp = ncpy % base;
	str[i] = tmp >= 10 ? 'a' + tmp - 10 : tmp + '0';
	if (is_neg == 1 && base == 10)
		str[++i] = '-';
	str[i + 1] = 0;
	return (ft_strrev(str));
}

char		*ft_itoa_base_up(long long n, int base)
{
	int					i;
	char				*str;
	int					is_neg;
	unsigned long long	ncpy;
	int					tmp;

	i = 0;
	is_neg = 0;
	(n < 0) && (is_neg = 1);
	ncpy = M(n);
	str = (char *)malloc(50);
	if (!str)
		return (0);
	while (ncpy >= (unsigned long long)base)
	{
		tmp = ncpy % base;
		str[i++] = tmp >= 10 ? 'A' + tmp - 10 : tmp + '0';
		ncpy /= base;
	}
	tmp = ncpy % base;
	str[i] = tmp >= 10 ? 'A' + tmp - 10 : tmp + '0';
	if (is_neg == 1 && base == 10)
		str[++i] = '-';
	str[i + 1] = 0;
	return (ft_strrev(str));
}

char		*ft_itoa_base_udw(unsigned long long ncpy, int base)
{
	int					i;
	char				*str;
	int					tmp;

	i = 0;
	str = (char *)malloc(50);
	if (!str)
		return (0);
	while (ncpy >= (unsigned long long)base)
	{
		tmp = ncpy % base;
		str[i++] = tmp >= 10 ? 'a' + tmp - 10 : tmp + '0';
		ncpy /= base;
	}
	tmp = ncpy % base;
	str[i] = tmp >= 10 ? 'a' + tmp - 10 : tmp + '0';
	str[i + 1] = 0;
	return (ft_strrev(str));
}

char		*ft_itoa_base_uup(unsigned long long ncpy, int base)
{
	int					i;
	char				*str;
	int					tmp;

	i = 0;
	str = (char *)malloc(50);
	if (!str)
		return (0);
	while (ncpy >= (unsigned long long)base)
	{
		tmp = ncpy % base;
		str[i++] = tmp >= 10 ? 'A' + tmp - 10 : tmp + '0';
		ncpy /= base;
	}
	tmp = ncpy % base;
	str[i] = tmp >= 10 ? 'A' + tmp - 10 : tmp + '0';
	str[i + 1] = 0;
	return (ft_strrev(str));
}
