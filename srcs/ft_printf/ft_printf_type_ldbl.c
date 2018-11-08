/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_long_double.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:44:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/27 15:53:49 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Get argument prefix depending on its associated flags and specifier
*/

static void			get_prefix(t_ptf *ptf, char *ptr, char *prefix)
{
	if (ft_strchr(ptf->flags, '+'))
		ft_strcat(prefix, ptr[0] == '-' ? "" : "+");
	else if (ft_strchr(ptf->flags, ' '))
		ft_strcat(prefix, " ");
	if (ptf->spec == 'a' || ptf->spec == 'A')
	{
		if (*ptr == '-' || *ptr == '+')
		{
			ft_strncat(prefix, ptr, 1);
			ptr = ft_strcpy(ptr, ptr + 1);
		}
		ft_strcat(prefix, ptf->spec == 'A' ? "0X" : "0x");
	}
}

/*
** Converts the exponent to ascii representation for aAeE conversions
** Returns 0 if converted double is invalid, 1 otherwise
*/

static int			get_suffix(char *buff, char *suffix, char spec, int expn)
{
	int min;
	int i;

	min = 0;
	i = 0;
	if (!(ft_strcasestr(buff, "nan") || ft_strcasestr(buff, "inf")))
	{
		min = expn < 0 ? 1 : 0;
		expn = expn < 0 ? -expn : expn;
		while (expn || (i < (spec == 'a' || spec == 'A' ? 1 : 2)))
		{
			ft_ccat(suffix, expn % 10 + '0');
			expn /= 10;
			i++;
		}
		ft_ccat(suffix, min ? '-' : '+');
		if (ft_strchr("eE", spec))
			ft_ccat(suffix, spec);
		else
			ft_ccat(suffix, spec == 'A' ? 'P' : 'p');
		suffix = ft_strrev(suffix);
		return (1);
	}
	return (0);
}

/*
** Does the dtoa conversion depending on the precision's and buffer's size
** Returns the exponent computed from dtoa
*/

static int			get_conv(t_ptf *ptf, t_ldbl param, char *tmp, int expn)
{
	if (ptf->precision > MAX_DBL_PRECISION)
		expn = ft_printf_dtoa(param, MAX_DBL_PRECISION, tmp, ptf->spec);
	else if (ptf->precision < 0 && ft_strchr("aA", ptf->spec))
		expn = ft_printf_dtoa(param, MAX_DBL_PRECISION, tmp, ptf->spec);
	else if (ptf->precision < 0)
		expn = ft_printf_dtoa(param, 6, tmp, ptf->spec);
	else
		expn = ft_printf_dtoa(param, ptf->precision, tmp, ptf->spec);
	if (ft_strchr(ptf->flags, '#') && !ft_strchr(tmp, '.'))
		tmp[ft_strlen(tmp)] = '.';
	return (expn);
}

/*
** Converts param depending on its associated flags and specifier
** Decides if a gG spec results in a eE or fF conversion depending on exponent
** Trim trailing zeros depending on conversion type
*/

static void			get_arg(t_ptf *ptf, t_ldbl param, char *tmp, char *suffix)
{
	int		expn;
	int		i;

	if (ft_strchr("gG", ptf->spec))
		ptf->precision = !ptf->precision ? 1 : ptf->precision;
	expn = get_conv(ptf, param, tmp, 0);
	i = (int)ft_strlen(tmp) - 1;
	while (tmp[i] == '0')
		i--;
	if (ft_strchr("aA", ptf->spec) && ptf->precision < 0)
		tmp[tmp[i] == '.' ? i : i + 1] = '\0';
	if (ft_strchr("gG", ptf->spec))
	{
		if (expn < -4 || ((ptf->precision >= 0 && expn >= ptf->precision)
					|| (ptf->precision < 0 && expn > 6)))
			ptf->spec = ptf->spec == 'G' ? 'E' : 'e';
		if (!ft_strchr(ptf->flags, '#'))
			tmp[tmp[i] == '.' ? i : i + 1] = '\0';
		ptf->precision = 0;
	}
	if (ft_strchr("aAeE", ptf->spec))
	{
		if (!(get_suffix(tmp, suffix, ptf->spec, expn)))
			ptf->precision = 0;
	}
}

/*
** Convert a long double to its ascii representation in tmp
*/

int					ft_printf_type_ldbl(t_ptf *ptf, t_ldbl param)
{
	char	tmp[MAX_DBL_LEN + MAX_DBL_PRECISION + 1];
	size_t	size;
	char	prefix[5];
	char	suffix[7];
	int		ret;

	ft_bzero(tmp, MAX_DBL_LEN + MAX_DBL_PRECISION + 1);
	ft_bzero(prefix, 5);
	ft_bzero(suffix, 7);
	size = 0;
	ret = 0;
	get_arg(ptf, param, tmp, suffix);
	if (!(ft_strcasestr(tmp, "nan") || ft_strcasestr(tmp, "inf")))
		get_prefix(ptf, tmp, prefix);
	size = ft_strlen(tmp);
	if (ptf->precision > MAX_DBL_PRECISION)
		ptf->precision -= MAX_DBL_PRECISION;
	else
		ptf->precision = ptf->precision < 0 ? -1 : 0;
	ptf->width -= (int)(size + ft_strlen(prefix) + ft_strlen(suffix));
	ft_printf_print(ptf, prefix, tmp, (int)size);
	ft_printf_buff_cat(ptf, suffix, ft_strlen(suffix));
	return (1);
}
