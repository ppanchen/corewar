/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:02:18 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/29 14:03:01 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = (char *)malloc(size);
	if (!mem)
		return (0);
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
