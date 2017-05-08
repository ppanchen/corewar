/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:28:12 by ppanchen          #+#    #+#             */
/*   Updated: 2017/05/05 18:28:12 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int 	ret_pc(int current, int shift)
{
	int ret;

	ret  = current + shift;
	if (ret >= 4096)
		ret -= 4096;
	return (ret);
}

unsigned char 					*to_little_endian(int num)
{
	unsigned char	*arr;
	unsigned char 	*pointer;
	int				i;
	int 			j;

	pointer = (unsigned char *)&num;
	arr = (unsigned char *)malloc(sizeof(unsigned char) * 4);
	i = -1;
	j = 3;
	while (++i < 4)
	{
		arr[j] = pointer[i];
		j--;
	}
	return (arr);
}

void					place_on_field(unsigned char *str, int pc)
{
	int i;

	i = -1;
	while (++i < 4)
		g_field[pc + i] = str[i];
}