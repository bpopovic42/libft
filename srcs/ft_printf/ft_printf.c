/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:54 by bopopovi          #+#    #+#             */
/*   Updated: 2019/08/29 16:50:38 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Printf version including 'aAcCdDeEfFgGinoOpsSuUxX' standard conversions
** Non standard conversions are :
** 'bB' for binary and 'r' for non-printable strings (octal form)
** Flags implemented :
** '-+# .hjlz*'
** Include a color format handling (refer to ft_printf.h for details)
** This printf version uses no malloc
*/

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vdprintf(1, format, ap);
	va_end(ap);
	if (ret < 0)
		return (1);
	return (ret);
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list		ap;
	int			ret;

	if (fd < 0)
		return (-1);
	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	if (ret < 0)
		return (1);
	return (ret);
}
