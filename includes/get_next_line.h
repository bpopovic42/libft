/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:45:59 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/25 00:13:37 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024
# define GNL_ERROR -1
# define GNL_EOF 0
# define GNL_READ 1

# include "libft.h"


typedef struct	s_gnl
{
	char		*data;
	size_t		data_len;
	char		buff[BUFF_SIZE + 1];
	int			newline_index;
	size_t		eol_index;
	int			status;
	int			has_newline;
}				t_gnl;

int					get_next_line(const int fd, char **line);

#endif
