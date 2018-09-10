/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:44:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/06 14:38:43 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Convert param from wchar_t to a char[5] multibyte sequence
** Returns -1 in case of error, 1 otherwise
*/

int			ft_printf_type_char(t_ptf *ptf, wchar_t param)
{
	char	mbs[5];
	int		size;

	ft_bzero(mbs, 5);
	size = 1;
	if (ft_strchr(ptf->flags, 'l'))
	{
		if (param && (size = ft_wctomb((unsigned char*)mbs, param)) < 0)
			return (-1);
	}
	else
		*mbs = (char)param;
	ptf->width -= size;
	ft_printf_print(ptf, "\0", (char*)mbs, size);
	return (1);
}
