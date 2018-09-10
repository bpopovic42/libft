/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:04:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/06 16:48:24 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Parse and write a color code from format string
** Returns 1 if the character sequence in between '{}' isn't recognized,
** 0 otherwise
*/

int		ft_printf_color(t_ptf *ptf)
{
	ft_printf_dump_fmt(ptf);
	if (!ft_strncmp(ptf->fmt.format, "{eoc}", 5))
		ft_printf_buff_cat(ptf, FT_PRINTF_EOC, 5);
	else if (!ft_strncmp(ptf->fmt.format, "{red}", 5))
		ft_printf_buff_cat(ptf, FT_PRINTF_RED, 5);
	else if (!ft_strncmp(ptf->fmt.format, "{green}", 7))
		ft_printf_buff_cat(ptf, FT_PRINTF_GRN, 5);
	else if (!ft_strncmp(ptf->fmt.format, "{blue}", 6))
		ft_printf_buff_cat(ptf, FT_PRINTF_BLU, 5);
	else if (!ft_strncmp(ptf->fmt.format, "{yellow}", 8))
		ft_printf_buff_cat(ptf, FT_PRINTF_YLW, 5);
	else if (!ft_strncmp(ptf->fmt.format, "{cyan}", 6))
		ft_printf_buff_cat(ptf, FT_PRINTF_CYA, 5);
	else if (!ft_strncmp(ptf->fmt.format, "{magenta}", 9))
		ft_printf_buff_cat(ptf, FT_PRINTF_MAG, 5);
	else
		return (1);
	while (*(ptf->fmt.format) != '}')
		ptf->fmt.format++;
	ptf->fmt.format++;
	return (0);
}
