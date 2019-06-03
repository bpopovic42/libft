/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:06:52 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/03 18:54:19 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Check wether provided specifier exists or if it is a '%'
** If specifier isn't recognized it is treated as the arg to a 'c' conversion
** Else send specifier's corresponding va_arg to the associated function
** Returns 1 in case of success, -1 otherwise
*/

static int			treat_arg_by_type(t_ptf *ptf, va_list ap)
{
	char	spec;

	spec = ptf->spec;
	if (!ft_printf_is_spec(spec) || spec == '%')
	{
		ptf->spec = 'c';
		if (spec == '%')
			return (ft_printf_type_mod(ptf));
		else
			return (ft_printf_type_char(ptf, (wchar_t)spec));
	}
	else if (ft_strchr("bBdDioOuUxXp", spec))
		return (ft_printf_type_int(ptf, va_arg(ap, int64_t)));
	else if (spec == 'r' || spec == 's' || spec == 'S')
		return (ft_printf_type_str(ptf, (wchar_t*)va_arg(ap, int64_t)));
	else if (spec == 'c' || spec == 'C')
		return (ft_printf_type_char(ptf, (wchar_t)va_arg(ap, int64_t)));
	else if (ft_strchr("aAeEfFgG", spec) && ft_strchr(ptf->flags, 'L'))
		return (ft_printf_type_ldbl(ptf, va_arg(ap, long double)));
	else if (ft_strchr("aAeEfFgG", spec))
		return (ft_printf_type_dbl(ptf, va_arg(ap, double)));
	else if (spec == 'n')
		return (ft_printf_type_n(ptf, va_arg(ap, int*)));
	return (-1);
}

/*
** Called if a '%' has been encountered and that it wasn't followed by a '\0'
** Returns size of treated argument if flags weren't directly followed by '\0'
** Returns 0 otherwise
*/

static int			treat_arg(t_ptf *ptf, va_list ap)
{
	uint64_t	i;
	int			ret;

	i = 1;
	ret = 0;
	i = ft_printf_get_flags(ptf, ap, i + ptf->fmt.i) - ptf->fmt.i;
	if (ptf->spec)
	{
		ret = treat_arg_by_type(ptf, ap);
		ptf->fmt.format += i + 1;
		ptf->fmt.i = 0;
	}
	return (ret);
}

/*
** Parse the format string for '%' or '{' until its end
** Add rest of the format string to buffer if anything's left
** Returns totabl nbr of characters written in case of success, -1 otherwise
*/

static int64_t		parse_fmt(t_ptf *ptf, va_list ap)
{
	int				ret;
	const char		**fmt;
	uint64_t		*i;

	ret = 0;
	fmt = &(ptf->fmt.format);
	i = &(ptf->fmt.i);
	while ((*fmt)[*i])
	{
		while ((*fmt)[*i] && (*fmt)[*i] != '%' && (*fmt)[*i] != '{')
			(*i)++;
		if ((*fmt)[*i] == '%')
		{
			if (!(*fmt)[*i + 1])
				break;
			else if ((ret = treat_arg(ptf, ap)) < 1)
				return (ret);
		}
		else if ((*fmt)[*i] == '{')
			*i += (uint64_t)ft_printf_color(ptf);
	}
	if (**fmt)
		ft_printf_buff_cat(ptf, (char*)*fmt, *i);
	return ((int64_t)ptf->buff.read);
}

/*
** Initialize ptf structure and send input to parse_fmt
** Write what's left in the buffer and terminate
** Returns total nbr of characters written in case of success, -1 otherwise
*/

int					ft_vdprintf(int fd, const char *restrict fmt, va_list ap)
{
	int				ret;
	t_ptf			ptf;

	ptf.buff.pos = 0;
	ptf.buff.read = 0;
	ptf.fmt.format = fmt;
	ptf.fmt.i = 0;
	ptf.fd = fd;
	if ((ret = (int)parse_fmt(&ptf, ap)) < 0)
	{
		if (write(fd, ptf.buff.buff, ptf.buff.pos) < 0)
			exit(-1);
		return (-1);
	}
	if (ptf.buff.pos > 0)
	{
		if (write(fd, ptf.buff.buff, ptf.buff.pos) < 0)
			exit(-1);
		ptf.buff.read += ptf.buff.pos;
	}
	return ((int)ptf.buff.read);
}
