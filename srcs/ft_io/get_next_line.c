/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:42:42 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/24 23:10:06 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static void	init_reader(t_gnl *reader)
{
	reader->data = NULL;
	reader->data_len = 0;
	reader->eol_index = 0;
	reader->has_newline = 0;
	reader->newline_index = 0;
	reader->status = 0;
}

static int	add_file_remains_to_dict(const int fd, t_gnl *reader, t_dict **list)
{
	char	*file_remains;
	size_t	remains_len;

	if (reader->has_newline)
	{
		file_remains = reader->data + (reader->newline_index + 1);
		remains_len = ft_strlen(file_remains) + 1;
		if (ft_dictadd(list, fd, file_remains, remains_len) < 0)
			return (-1);
	}
	return (0);
}

static int	reader_has_eol(t_gnl *reader)
{
	if (reader->status == 0)
	{
		if (reader->data)
		{
			reader->data_len = ft_strlen(reader->data);
			reader->eol_index = reader->data_len;
		}
		return (1);
	}
	else if ((reader->newline_index = ft_strchri(reader->data, '\n')) >= 0)
	{
		reader->has_newline = 1;
		reader->eol_index = reader->newline_index;
		reader->data_len = ft_strlen(reader->data);
		return (1);
	}
	return (0);
}

static void	read_file_until_eol(const int fd, t_gnl *reader)
{
	reader->status = GNL_READ;
	while (!reader_has_eol(reader))
	{
		if ((reader->status = (int)read(fd, reader->buff, BUFF_SIZE)) > 0)
		{
			reader->buff[reader->status] = '\0';
			if (!(reader->data = ft_strappend(reader->data, reader->buff)))
				reader->status = GNL_ERROR;
		}
		if (reader->status < 0)
			break ;;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_dict	*list;
	t_gnl			reader;

	init_reader(&reader);
	if (fd >= 0 && line)
	{
		reader.data = (char*)ft_dictget(&list, fd);
		read_file_until_eol(fd, &reader);
		if (reader.status >= 0 && reader.data_len > 0)
		{
			if (!(*line = ft_strsub(reader.data, 0, reader.eol_index)))
				reader.status = GNL_ERROR;
			else if (add_file_remains_to_dict(fd, &reader, &list) < 0)
				reader.status = GNL_ERROR;
			else
				reader.status = GNL_READ;
			ft_strdel(&reader.data);
		}
		else if (reader.status == 0 && reader.data_len == 0)
			reader.status = GNL_EOF;
	}
	else
		reader.status = GNL_ERROR;
	return (reader.status);
}
