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
	while (ret >= 4096)
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
	arr = (unsigned char *)ft_memalloc(4);
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
	{
		while (pc + i >= 4096)
			pc -= 4096;
		g_field[pc + i] = str[i];
//		print_field();
	}
}

char			*c_bite_to_str(int coding_bite)
{
	char	*str;
	char 	*zero;
	int 	i;

	str = ft_itoa_base_dw(coding_bite, 2);
	i = (int)ft_strlen(str);
	while (i < 8)
	{
		zero = ft_strdup("0");
		str = ft_strjoin_free(&zero, &str);
		i++;
	}
	return (str);
}

void			print_field(void)
{
	int i;
	int j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		ft_printf("%#.4x : ", i * 64);
		while (j < 64)
		{
			ft_printf("%.2x ", g_field[j + i * 64]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}