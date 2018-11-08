/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:42:42 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 18:50:57 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int			get_next_line(const int fd, char **line)
{
	static t_hash	*list;
	char			*rest;
	char			buff[BUFF_SIZE + 1];
	int				i;
	int				ret;

	ret = 1;
	if (fd < 0 || !(line))
		return (-1);
	rest = (char*)ft_hashget(&list, fd);
	while ((i = ft_strchri(rest, '\n')) < 0 && ret)
	{
		if ((ret = (int)read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[ret] = '\0';
		rest = ft_strappend(rest, buff);
	}
	*line = (i >= 0) ? ft_strsub(rest, 0, (size_t)i) : ft_strdup(rest);
	if (i++ >= 0)
		ft_hashadd(&list, fd, rest + i, ft_strlen(rest + i) + 1);
	ret = (rest[0]) ? 1 : ret;
	ft_strdel(&rest);
	return (ret);
}
