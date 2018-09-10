/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:10:37 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/09 22:09:12 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Round double's ascii representation from the last digit
*/

static void		round_dbl(char *buff)
{
	size_t i;

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

/*
** Converts double value to ascii base using *bstr charset
*/

static int		dtoa_base(double *val, char *buff, int i, char *bstr)
{
	double	tmp;
	int		ret;
	int		base;

	tmp = *val;
	ret = 0;
	base = (int)ft_strlen(bstr);
	while (i)
	{
		ft_ccat(buff, bstr[(int64_t)(tmp)]);
		tmp -= (int64_t)tmp;
		tmp = tmp * base;
		*val *= base;
		if (i < 0)
			i++;
		else
			i--;
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

static int		adjust(double *val, char spec)
{
	int		i;
	int		base;

	i = 0;
	base = ft_toupper(spec) == 'A' ? 2 : 10;
	if (*val > (base - 1) || *val < 1)
	{
		while ((int)*val > (base - 1) || (int)*val < 1)
		{
			if (*val > (base - 1))
			{
				*val /= base;
				i++;
			}
			else
			{
				*val *= base;
				i--;
			}
		}
	}
	return (i);
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
	if (!(ft_toupper(spec) == 'F' && (int)dbl->val == 0))
		expn = adjust(&(dbl->val), spec) + (ft_strchr("fF", spec) ? 1 : 0);
	if ((spec == 'G' || spec == 'g') || (spec == 'a' || spec == 'A'))
	{
		if (expn > -4 && expn < *prec && expn != 0 && ft_toupper(spec) != 'A')
			intpart_size = dtoa_base(&dbl->val, buff, expn + 1, bstr);
		else
			intpart_size = dtoa_base(&dbl->val, buff, 1, bstr);
		*prec -= (spec == 'G' || spec == 'g' ? intpart_size : 0);
	}
	else
		dtoa_base(&dbl->val, buff, ft_strchr("fF", spec) ? expn : 1, bstr);
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
