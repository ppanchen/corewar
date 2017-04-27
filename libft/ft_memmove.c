/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:54:53 by ppanchen          #+#    #+#             */
/*   Updated: 2016/11/29 14:20:26 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = malloc(len);
	if (tmp)
	{
		ft_memcpy(tmp, src, len);
		ft_memcpy(dst, tmp, len);
		free(tmp);
	}
	return (dst);
}
