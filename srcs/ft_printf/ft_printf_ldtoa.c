/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ldtoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:10:37 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/03 18:54:33 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Round double's ascii representation from the last digit
*/

static void		round_dbl(char *buff)
{
	size_t i;

	if (buff && *(buff))
	{
		i = ft_strlen(buff) - 1;
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
				break;
			}
			else if (buff[i] == '.')
				break;
			i--;
		}
	}
}

/*
** Converts double value to ascii base using *bstr charset
*/

static int		dtoa_base(t_ldbl *val, char *buff, int i, char *bstr)
{
	t_uldbl	tmp;
	int		ret;
	int		base;

	ret = 0;
	base = (int)ft_strlen(bstr);
	tmp.val = *val;
	while (i)
	{
		ft_ccat(buff, bstr[(int64_t)tmp.val > 0 ? (int64_t)tmp.val % base : 0]);
		tmp.val -= (int64_t)tmp.val;
		tmp.val *= base;
		*val *= base;
		i += i < 0 ? 1 : -1;
		ret++;
	}
	if (((int64_t)(tmp.val) % base) > (base / 2) && base == 10)
		round_dbl(buff);
	*val /= base;
	return (ret);
}

/*
** Adjust given double to a 1 digit integer part by multiplying or dividing
** Division and multiplication factor is defined by the spec associated base
** If base is denary then decimal factor is used, else factor is binary
** Returns the number of operations used to ajust the number
*/

static int		adjust(t_ldbl *val, char spe)
{
	int		i;
	int		base;

	i = 0;
	base = ft_toupper(spe) == 'A' ? 2 : 10;
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
			if (i < -200)
				return (0);
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

static int		getint(t_uldbl *dbl, int *prec, char *buff, char spe)
{
	int		expn;
	int		intpart_size;
	char	*bstr;

	bstr = spe == 'A' ? BASE_HEXA_UP : BASE_HEXA;
	bstr = ft_toupper(spe) == 'A' ? bstr : BASE_DENARY;
	expn = ft_toupper(spe) == 'F' ? 1 : adjust(&(dbl->val), spe);
	if ((spe == 'G' || spe == 'g') || (spe == 'a' || spe == 'A'))
	{
		if (ft_toupper(spe != 65) && expn > -4 && ((*prec >= 0 && expn < *prec)
			|| (*prec < 0 && expn < 6)) && expn != 0 && ft_toupper(spe) != 65)
			intpart_size = dtoa_base(&dbl->val, buff, expn + 1, bstr);
		else
			intpart_size = dtoa_base(&dbl->val, buff, 1, bstr);
		*prec -= (spe == 'G' || spe == 'g' ? intpart_size : 0);
	}
	else
		ft_printf_lltoa_base(buff + 1, BASE_DENARY, (int64_t)dbl->val);
	if (ft_strchr("EF", ft_toupper(spe)))
	{
		ft_strcpy(buff, buff + 2);
		buff[ft_strlen(buff) + 1] = '\0';
	}
	ft_ccat(buff, *prec ? '.' : '\0');
	return (expn);
}

/*
** Convert a long double to ascii in either denary or hexa base up to prec digit
** Base is instanciated depending on given spec
** Inf and NaN numbers are handled
** Conversion is written starting at (buff + 1) in case rounding would overflow
** Returns converted double's exponent or 0 if double is either Nan or inf
*/

int				ft_printf_ldtoa(t_ldbl val, int prec, char *buff, char spe)
{
	t_uldbl		dbl;
	int			expn;
	int			base;
	char		*bstr;

	dbl.val = val;
	bstr = BASE_DENARY;
	if (spe == 'a' || spe == 'A')
		bstr = spe == 'A' ? BASE_HEXA_UP : BASE_HEXA;
	base = (int)ft_strlen(bstr);
	if (dbl.bits.expn == 2047)
	{
		ft_strcat(buff, dbl.bits.mant ? "nan" : "\0");
		if (!dbl.bits.mant)
			ft_strcat(buff, dbl.bits.sign ? "-inf" : "inf");
		buff = ft_isupper(spe) ? ft_strtoupper(buff) : buff;
		return (0);
	}
	buff[0] = dbl.bits.sign ? '-' : buff[0];
	dbl.bits.sign = 0;
	expn = getint(&dbl, &prec, buff + 1, spe);
	dbl.val *= base;
	dtoa_base(&dbl.val, buff + 1, prec, bstr);
	buff = !buff[0] ? ft_strcpy(buff, buff + 1) : buff;
	return (expn);
}
