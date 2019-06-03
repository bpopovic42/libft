/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:11:54 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/03 18:54:10 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_is_flag(int c)
{
	return (ft_isdigit(c) || c == '-' || c == '+' || c == '#' || c == '.'
		|| c == 'h' || c == 'j' || c == 'l' || c == 'z' || c == ' '
			|| c == 'L' || c == '*');
}

int			ft_printf_is_spec(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
				|| c == 'X' || c == 'c' || c == 'C' || c == 'f' || c == 'F'
					|| c == 'b' || c == 'B' || c == '%' || c == 'e'
						|| c == 'E' || c == 'g' || c == 'G' || c == 'n'
							|| c == 'a' || c == 'A' || c == 'r');
}

/*
** Convert integer ascii representation to int
** If given representation exceeds INT_MAX resulting value is zero
** Returns index at which the representation ends
*/

size_t		ft_printf_atoi(const char *str, int *res)
{
	int			flag;
	size_t		i;

	i = 0;
	*res = 0;
	while (ft_isspace(str[i]))
		i++;
	flag = str[i] == '-' ? -1 : 1;
	i += str[i] == '-' || str[i] == '+' ? 1 : 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if ((long)(((long)*res * 10) + str[i] - '0') > 2147483647L)
		{
			*res = 0;
			while (str[i] && (str[i] >= '0' && str[i] <= '9'))
				i++;
			break;
		}
		*res = (*res * 10) + (str[i++] - '0');
	}
	*res *= flag;
	return (i);
}

/*
** Converts a int64_t int to its ascii representation in a given base
** Base is computed from the length of its associated charset *chrst
** Returns the conversion's ascii string length
*/

int			ft_printf_lltoa_base(char *buff, char *chrst, int64_t nb)
{
	t_uint				base;
	int					i;
	char				*ptr;
	uint64_t			tmp;

	i = 0;
	ptr = buff;
	base = (t_uint)ft_strlen(chrst);
	if (base > 16 || base < 2 || !ptr)
		return (-1);
	*ptr = nb < 0 ? '-' : '+';
	tmp = (uint64_t)(nb * (*ptr == '-' ? -1 : 1));
	ptr++;
	while (tmp || i < 1)
	{
		ptr[i] = chrst[tmp % (uint64_t)base];
		i++;
		tmp /= (uint64_t)base;
	}
	ptr[i] = '\0';
	ptr = ft_strrev(ptr);
	return (i);
}

/*
** Converts a uint64_t to its ascii representation in a given base
** Base is computed from the length of its associated charset *chrst
** Returns the conversion's ascii string length
*/

int			ft_printf_ulltoa_base(char *buff, char *chrst, uint64_t nb)
{
	t_uint	base;
	int		i;
	char	*ptr;

	i = 0;
	ptr = buff;
	base = (t_uint)ft_strlen(chrst);
	*ptr = '+';
	ptr++;
	if (base > 16 || base < 2)
		return (-1);
	while (nb || i < 1)
	{
		ptr[i] = chrst[nb % (uint64_t)base];
		i++;
		nb /= (uint64_t)base;
	}
	ptr[i] = '\0';
	ptr = ft_strrev(ptr);
	return (i);
}
