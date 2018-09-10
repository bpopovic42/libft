/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:44:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/06 19:47:19 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_arg_unsigned(t_ptf *ptf, char *res, int64_t param)
{
	if (ptf->spec == 'p')
		return (ft_printf_lltoa_base(res, ptf->base, (uint64_t)param));
	else if (ft_strchrn(ptf->flags, 'l') == 2)
		return (ft_printf_ulltoa_base(res, ptf->base, (uint64_t)param));
	else if (ft_strchr(ptf->flags, 'l'))
		return (ft_printf_ulltoa_base(res, ptf->base, (unsigned long)param));
	else if (ft_strchr(ptf->flags, 'j'))
		return (ft_printf_ulltoa_base(res, ptf->base, (uintmax_t)param));
	else if (ft_strchr(ptf->flags, 'z'))
		return (ft_printf_ulltoa_base(res, ptf->base, (size_t)param));
	else if (ft_strchrn(ptf->flags, 'h') == 2)
		return (ft_printf_ulltoa_base(res, ptf->base, (unsigned char)param));
	else if (ft_strchr(ptf->flags, 'h'))
		return (ft_printf_ulltoa_base(res, ptf->base, (unsigned short)param));
	else
		return (ft_printf_ulltoa_base(res, ptf->base, (unsigned)param));
}

static int			get_arg_signed(t_ptf *ptf, char *res, int64_t param)
{
	if (ft_strchrn(ptf->flags, 'l') == 2)
		return (ft_printf_lltoa_base(res, ptf->base, (int64_t)param));
	else if (ft_strchr(ptf->flags, 'l'))
		return (ft_printf_lltoa_base(res, ptf->base, (long)param));
	else if (ft_strchr(ptf->flags, 'j'))
		return (ft_printf_lltoa_base(res, ptf->base, (intmax_t)param));
	else if (ft_strchr(ptf->flags, 'z'))
		return (ft_printf_lltoa_base(res, ptf->base, (signed long)param));
	else if (ft_strchrn(ptf->flags, 'h') == 2)
		return (ft_printf_lltoa_base(res, ptf->base, (char)param));
	else if (ft_strchr(ptf->flags, 'h'))
		return (ft_printf_lltoa_base(res, ptf->base, (short)param));
	else
		return (ft_printf_lltoa_base(res, ptf->base, (int)param));
}

/*
** Compute prefix specified by argument flags and specifier
*/

static int			get_prefix(t_ptf *ptf, char *ptr, char *prfx)
{
	if (ft_strchr("bBdDi", ptf->spec))
	{
		if (ft_strchr(ptf->flags, '+') || (ptr[0] == '-'))
			ft_strcat(prfx, ptr[0] == '-' ? "-" : "+");
		else if (ft_strchr("dDi", ptf->spec) && ft_strchr(ptf->flags, ' '))
			ft_strcat(prfx, " ");
	}
	if (ft_strchr(ptf->flags, '#') && ft_strchr("xX", ptf->spec))
	{
		if (ptr[1] != '0')
			ft_strcat(prfx, ptf->spec == 'X' ? "0X" : "0x");
	}
	else if (ptf->spec == 'p')
		ft_strcat(prfx, "0x");
	else if (ptf->spec == 'b' || ptf->spec == 'B')
		ft_strcat(prfx, ptf->spec == 'b' ? "0b" : "0B");
	return ((int)ft_strlen(prfx));
}

/*
** Called if argument is valid
** Format the argument in relation to it's flags and specifier
** Then send it to the print_arg function
*/

static void			local_format_arg(t_ptf *ptf, char *prfx, char *ptr, int siz)
{
	int		htag;

	htag = ft_strchr(ptf->flags, '#') ? 1 : 0;
	if (ptf->precision > siz)
		ptf->precision -= siz;
	else
		ptf->precision = ptf->precision < 0 ? -1 : 0;
	if (ptf->precision < 1 && ft_toupper(ptf->spec) == 'O' && htag)
		ft_strcat(prfx, ptr[1] == '0' ? "" : "0");
	ptf->width -= (ptf->width > 0) ? ft_strlen(prfx) + (size_t)siz : 0;
	if (ptf->width > 0 && ptf->precision > 0)
		ptf->width -= ptf->precision;
	if (ft_toupper(ptf->spec) == 'B' && ptf->precision < 0)
		ptf->precision = 8 - (siz % 8 > 0 ? siz % 8 : 8);
	ft_printf_print(ptf, prfx, (ptr + 1), siz);
}

/*
** Converts a given integer type param to its formatted representation
*/

int					ft_printf_type_int(t_ptf *ptf, int64_t param)
{
	char	ptr[65];
	char	prfx[5];
	int		siz;

	ft_bzero(prfx, 5);
	if (ft_strchr("bBdDi", ptf->spec))
		siz = get_arg_signed(ptf, ptr, param);
	else
		siz = get_arg_unsigned(ptf, ptr, param);
	get_prefix(ptf, ptr, prfx);
	if (!(ft_toupper(ptf->spec) == 'O' && ft_strchr(ptf->flags, '#'))
		&& !param && !ptf->precision)
		ft_printf_print(ptf, prfx, NULL, 0);
	else
		local_format_arg(ptf, prfx, ptr, siz);
	return (1);
}
