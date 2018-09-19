/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:48:52 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/11 14:54:49 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Writes an int value to printf buffer in octal form
** Resulting representation is prefixed by a '\'
** Returns output's size
*/

static int	local_putnbr_octal(t_ptf *ptf, char value)
{
	char	tmp[4];
	int		i;

	i = 0;
	while (value)
	{
		tmp[i] = value % 8 + '0';
		value /= 8;
		i++;
	}
	tmp[i] = '\\';
	while (i >= 0)
	{
		if (ptf->buff.pos == FT_PRINTF_BUFF_SIZE)
		{
			if (write(ptf->fd, ptf->buff.buff, ptf->buff.pos) < 0)
				exit(-1);
			ptf->buff.read += ptf->buff.pos;
			ptf->buff.pos = 0;
		}
		ptf->buff.buff[ptf->buff.pos] = tmp[i];
		ptf->buff.pos++;
		i--;
	}
	return (i);
}

/*
** Write size input's characters from input to printf's buffer
** If a non-printable character is encountered,
** Then its octal representation is used
*/

void		ft_printf_buff_cat_npr(t_ptf *ptf, char *inp, uint64_t siz)
{
	int		i;
	char	*buff;

	i = 0;
	buff = ptf->buff.buff;
	while (siz)
	{
		if (ptf->buff.pos == FT_PRINTF_BUFF_SIZE)
		{
			if (write(ptf->fd, buff, ptf->buff.pos) < 0)
				exit(-1);
			ptf->buff.read += ptf->buff.pos;
			ptf->buff.pos = 0;
		}
		if (inp[i] > 31 && inp[i] < 127)
			buff[ptf->buff.pos] = inp[i];
		else
			ptf->buff.pos += (unsigned long)local_putnbr_octal(ptf, inp[i]);
		ptf->buff.pos++;
		siz--;
		i++;
	}
}

/*
** Writes size input's characters to printf's buffer
** If buffer reach its max size, buffer is dumped
*/

void		ft_printf_buff_cat(t_ptf *ptf, char *inp, uint64_t siz)
{
	int		i;
	char	*buff;

	i = 0;
	buff = ptf->buff.buff;
	while (siz)
	{
		if (ptf->buff.pos == FT_PRINTF_BUFF_SIZE)
		{
			if (write(ptf->fd, buff, ptf->buff.pos) < 0)
				exit(-1);
			ptf->buff.read += ptf->buff.pos;
			ptf->buff.pos = 0;
		}
		buff[ptf->buff.pos] = inp[i];
		ptf->buff.pos++;
		siz--;
		i++;
	}
}

/*
** Concatenates input n times in printf's buffer
*/

void		ft_printf_buff_catn(t_ptf *ptf, char *inp, uint64_t n)
{
	int len;

	len = (int)ft_strlen(inp);
	while (n--)
		ft_printf_buff_cat(ptf, inp, (uint64_t)len);
}

/*
** Writes previoulsy parsed format string part to output
** Reset its index
*/

void		ft_printf_dump_fmt(t_ptf *ptf)
{
	ft_printf_buff_cat(ptf, (char*)ptf->fmt.format, ptf->fmt.i);
	ptf->fmt.format += ptf->fmt.i;
	ptf->fmt.i = 0;
}
