/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:03:22 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/08 15:48:55 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrrev(char **arr)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (arr[j])
		j++;
	j--;
	i = 0;
	while (i < j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
	return (arr);
}
