/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:44:17 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/03 18:54:50 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Used to print the 'S' argument in regard to wchar_t handling rules
** Function prints no more than n bytes
*/

void			ft_printf_print_wcs(t_ptf *ptf, wchar_t *input, int n)
{
	unsigned char	bytes[4];
	int				total_b;
	int				len;
	int				i;

	total_b = 0;
	i = 0;
	len = 0;
	while (input[i] != L'\0')
	{
		ft_bzero(bytes, 4);
		len = ft_wctomb(bytes, input[i]);
		total_b += len;
		if (total_b <= n)
		{
			ft_printf_buff_cat(ptf, (char*)bytes, (uint64_t)len);
			if (total_b == n)
				break;
		}
		else
			break;
		i++;
	}
}

/*
** Dump parsed part of the format string
** Decides wether width should be space or zero
** Then proceeds to print formated arg and its computed prefix and or suffix
** If the specifier is 'S' or 'r' args are send to their dedicated functions
*/

void			ft_printf_print(t_ptf *ptf, char *prfx, char *input, int n)
{
	char *width;

	ft_printf_dump_fmt(ptf);
	width = " ";
	if (ft_strchr(ptf->flags, '0'))
		width = ptf->precision < 0 || ft_strchr("rsScC", ptf->spec) ? "0" : " ";
	if (ft_strlen(prfx) && *width == '0')
		ft_printf_buff_cat(ptf, prfx, (uint64_t)ft_strlen(prfx));
	if (!ft_strchr(ptf->flags, '-') && ptf->width > 0)
		ft_printf_buff_catn(ptf, width, (uint64_t)ptf->width);
	if (ft_strlen(prfx) && *width == ' ')
		ft_printf_buff_cat(ptf, prfx, (uint64_t)ft_strlen(prfx));
	if (ft_strchr("BDIOUXP", ft_toupper(ptf->spec)) && ptf->precision > 0)
		ft_printf_buff_catn(ptf, "0", (uint64_t)ptf->precision);
	if (ptf->spec == 'S')
		ft_printf_print_wcs(ptf, (wchar_t*)input, n);
	else if (ptf->spec == 'r')
		ft_printf_buff_cat_npr(ptf, input, (uint64_t)n);
	else if (ptf->spec != 'S')
		ft_printf_buff_cat(ptf, input, (uint64_t)n);
	if (ft_strchr("AEF", ft_toupper(ptf->spec)) && ptf->precision > 0)
		ft_printf_buff_catn(ptf, "0", (uint64_t)ptf->precision);
	if (ft_strchr(ptf->flags, '-') && (int)ptf->width > 0)
		ft_printf_buff_catn(ptf, " ", (uint64_t)ptf->width);
}
