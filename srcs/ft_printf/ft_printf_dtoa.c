/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:10:37 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/11 22:31:46 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Round double's ascii representation from the last digit
*/

static void		round_dbl(char *buff)
{
	size_t i;

	if (buff && *buff)
	{
		i = ft_strlen(buff + 1);
		while (i)
		{
			if (buff[i] == '9')
				buff[i] = '0';
			else if (buff[i] != '.')
			{
				if (i == 0)
					buff[i] = '1';
				else
					buff[i]++;
				break ;
			}
			i--;
		}
	}
}

/*
** Converts double value to ascii base using *bstr charset
*/

#include <stdio.h>

static int		dtoa_base(double *val, char *buff, int i, char *bstr)
{
	t_dbl	tmp;
	int		ret;
	int		base;

	ret = 0;
	base = (int)ft_strlen(bstr);
	while (i < 1)
	{
		*val /= base;
		i++;
	}
	tmp.val = *val;
	while (i)
	{
		ft_ccat(buff, bstr[(int)(tmp.val) > 0 ? (int)(tmp.val) % base : 0]);
		tmp.val -= (int64_t)tmp.val;
		tmp.val *= base;
		*val *= base;
		i += i < 0 ? 1 : -1;
		ret++;
	}
	*val /= base;
	*val -= (int64_t)(*val);
	return (ret);
}

/*
** Adjust given double to a 1 digit integer part by multiplying or dividing
** Division and multiplication factor is defined by the spec associated base
** If base is denary then decimal factor is used, else factor is binary
** Returns the number of operations used to ajust the number
*/

static double		adjust(double val, int *i, char spec)
{
	int		base;

	*i = 0;
	base = ft_toupper(spec) == 'A' ? 2 : 10;
	if (val > (base - 1) || val < 1)
	{
		while ((int)val > (base - 1) || (int)val < 1)
		{
			if (val > (base - 1))
			{
				val /= base;
				(*i)++;
			}
			else
			{
				val *= base;
				(*i)--;
			}
			if (*i < -200)
				return (0);
		}
	}
	return (val);
}

/*
** Gets converted integer part of the given double value
** Begins by getting the absolute number value, then gets target base from spec
** Computes the exponent by adjusting it to a 1 digit integer part
** Adds a '.' if needed
** Returns computed exponent
*/

static int		getint(t_dbl *dbl, int *prec, char *buff, char spec)
{
	int		expn;
	int		intpart_size;
	char	*bstr;

	buff[0] = dbl->bits.sign ? '-' : buff[0];
	dbl->bits.sign = 0;
	intpart_size = 0;
	bstr = BASE_DENARY;
	if (spec == 'a' || spec == 'A')
		bstr = spec == 'A' ? BASE_HEXA_UP : BASE_HEXA;
	expn = 1;
	adjust(dbl->val, &expn, spec);
	if ((spec == 'G' || spec == 'g') || (spec == 'a' || spec == 'A'))
	{
		if (expn > -4 && expn < *prec && expn != 0 && ft_toupper(spec) != 'A')
		{
			intpart_size = ft_printf_lltoa_base(buff, BASE_DENARY, (int64_t)dbl->val);
			dbl->val -= (int64_t)dbl->val;
		}
		else
		{
			dbl->val = adjust(dbl->val, &expn, spec);
			intpart_size = dtoa_base(&(dbl->val), buff, 1, bstr);
		}
		*prec -= (spec == 'G' || spec == 'g' ? intpart_size : 0);
	}
	else if ((expn > 12 && ft_toupper(spec) == 'F'))
	{
		dbl->val = adjust(dbl->val, &expn, spec);
		dtoa_base(&(dbl->val), buff, ft_strchr("fF", spec) ? expn : 1, bstr);
	}
	else if (ft_toupper(spec) == 'E')
	{
		intpart_size = 1;
		ft_printf_lltoa_base(buff, BASE_DENARY, (int64_t)dbl->val);
		buff[2] = '\0';
	}
	ft_ccat(buff, *prec ? '.' : '\0');
	return (expn);
}

/*
** Convert a double to ascii in either denary or hexa base up to prec digits
** Base is instanciated depending on given spec
** Inf and NaN numbers are handled
** Conversion is written starting at (buff + 1) in case rounding would overflow
** Returns converted double's exponent or 0 if double is either Nan or inf
*/

int				ft_printf_dtoa(double val, int prec, char *buff, char spec)
{
	t_dbl		dbl;
	int			expn;
	int			base;
	char		*bstr;

	dbl.val = val;
	bstr = BASE_DENARY;
	if (spec == 'a' || spec == 'A')
		bstr = spec == 'A' ? BASE_HEXA_UP : BASE_HEXA;
	base = (int)ft_strlen(bstr);
	if (dbl.bits.expn == 2047)
	{
		ft_strcat(buff, dbl.bits.mant ? "nan" : "\0");
		if (!dbl.bits.mant)
			ft_strcat(buff, dbl.bits.sign ? "-inf" : "inf");
		buff = ft_isupper(spec) ? ft_strtoupper(buff) : buff;
		return (0);
	}
	expn = getint(&dbl, &prec, buff + 1, spec);
	dbl.val *= base;
	dtoa_base(&dbl.val, buff + 1, prec, bstr);
	if ((int)(dbl.val * base) > (base / 2))
		round_dbl(buff);
	buff = !buff[0] ? ft_strcpy(buff, buff + 1) : buff;
	return (expn);
}
