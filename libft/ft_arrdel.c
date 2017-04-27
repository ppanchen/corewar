/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 15:40:32 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/08 15:46:33 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel(char ***arr)
{
	int i;

	i = -1;
	while ((*arr)[++i])
		ft_strdel(&(*arr)[i]);
	free(*arr);
	*arr = NULL;
}

void	ft_arrmemdel(void ***arr)
{
	int i;

	i = -1;
	while ((*arr)[++i])
		ft_memdel(&(*arr)[i]);
	free(*arr);
	*arr = NULL;
}
