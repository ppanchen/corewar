/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:27:59 by ppanchen          #+#    #+#             */
/*   Updated: 2017/01/13 17:31:22 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_str(char **buf, char **line)
{
	char	*n;
	char	*tmp;

	n = ft_strchr(*buf, '\n');
	!n && (n = ft_strchr(*buf, '\0'));
	*line = ft_strsub(*buf, 0, n - *buf);
	tmp = *buf;
	*buf = ft_strdup(n + 1);
	ft_strdel(&tmp);
	return (1);
}

void	join_free(char **retstr, char *buf)
{
	char	*tmp;

	tmp = *retstr;
	*retstr = ft_strjoin(*retstr, buf);
	ft_strdel(&tmp);
}

void	dup_free(char **retstr, char **n)
{
	char	*tmp;

	tmp = *retstr;
	*retstr = **n ? ft_strdup(*n + 1) : ft_strdup(*n);
	ft_strdel(&tmp);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*n;
	static char *retstr = NULL;

	if (retstr && ft_strchr(retstr, '\n') != 0)
		return (check_str(&retstr, line));
	n = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		join_free(&retstr, buf);
		if ((n = ft_strchr(retstr, '\n')) != 0)
			break ;
	}
	if ((ret == 0 && ft_strlen(retstr) == 0) || ret == -1)
	{
		if (line)
			*line = "";
		return (line ? ret : -1);
	}
	!n && (n = ft_strchr(retstr, '\0'));
	line && (*line = ft_strsub(retstr, 0, n - retstr));
	dup_free(&retstr, &n);
	return (line ? 1 : -1);
}
