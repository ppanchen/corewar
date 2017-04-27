/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:02:36 by ppanchen          #+#    #+#             */
/*   Updated: 2016/12/08 17:33:26 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *ret;
	t_list *tmp;

	if (!lst)
		return (0);
	tmp = lst;
	new = f(tmp);
	ret = new;
	while (tmp->next)
	{
		tmp = lst->next;
		lst = lst->next;
		new->next = f(tmp);
		new = new->next;
	}
	return (ret);
}
