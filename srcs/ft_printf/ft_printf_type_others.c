/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_others.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:05:27 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/11 18:42:01 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Write number of characters read into *n
*/

int		ft_printf_type_n(t_ptf *ptf, int *n)
{
	ft_printf_dump_fmt(ptf);
	if (n && *n)
		*n = (int)(ptf->buff.read + ptf->buff.pos + ptf->fmt.i);
	return (1);
}

/*
** Print a formatted '%'
*/

int		ft_printf_type_mod(t_ptf *ptf)
{
	ptf->width--;
	ptf->precision = -1;
	ft_printf_print(ptf, "\0", "%", 1);
	return (1);
}
