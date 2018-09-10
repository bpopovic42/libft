/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:13:40 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/28 02:28:52 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int		get_nbr_len(unsigned int nbr, unsigned int b_len)
{
	unsigned int len;

	len = 0;
	if (nbr == 0)
		return ((unsigned int)1);
	while (nbr != 0)
	{
		nbr /= b_len;
		len++;
	}
	return (len);
}

static int				is_valid_base(char *base)
{
	size_t	i;

	i = 0;
	while (base[i] && !ft_issign(base[i]) && ft_char_count(base, base[i]) <= 1)
		i++;
	return (i > 1 && !base[i] ? 1 : 0);
}

char					*ft_itoa_base(int nbr, char *base)
{
	t_uint	tmp;
	t_uint	len;
	t_uint	b_len;
	char	*res;

	if (!base || !is_valid_base(base))
		return (NULL);
	b_len = (unsigned int)ft_strlen(base);
	res = NULL;
	tmp = nbr < 0 ? (unsigned int)(nbr * -1) : (unsigned int)nbr;
	len = get_nbr_len(tmp, b_len) + (nbr < 0 ? 1 : 0);
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[len--] = '\0';
	while (tmp > b_len - 1)
	{
		res[len--] = base[tmp % b_len];
		tmp /= b_len;
	}
	res[len] = base[tmp % b_len];
	res[0] = nbr < 0 ? '-' : res[0];
	return (res);
}
