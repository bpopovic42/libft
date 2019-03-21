/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:42:42 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/21 20:58:21 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int			get_next_line(const int fd, char **line)
{
	static t_dict	*list;
	char			*rest;
	char			buff[BUFF_SIZE + 1];
	int				i;
	int				ret;

	ret = 1;
	if (fd < 0 || !(line))
		return (-1);
	rest = (char*)ft_dictget(&list, fd);
	while ((i = ft_strchri(rest, '\n')) < 0 && ret)
	{
		if ((ret = (int)read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[ret] = '\0';
		if (!(rest = ft_strappend(rest, buff)))
			return (-1);
	}
	if (rest[0])
	{
		if (!(*line = ft_strsub(rest, 0, i >= 0 ? (size_t)i : ft_strlen(rest))))
			return (-1);
	}
	if (i++ >= 0)
	{
		if (ft_dictadd(&list, fd, rest + i, ft_strlen(rest + i) + 1) < 0)
			return (-1);
	}
	ret = (rest[0]) ? 1 : ret;
	ft_strdel(&rest);
	return (ret);
}
