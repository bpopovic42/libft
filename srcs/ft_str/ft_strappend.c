/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:50:36 by bopopovi          #+#    #+#             */
/*   Updated: 2018/05/29 14:57:31 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *dst, char *append)
{
	size_t	d_len;
	size_t	a_len;
	char	*new;

	d_len = dst ? ft_strlen(dst) : 0;
	a_len = append ? ft_strlen(append) : 0;
	if (!(new = ft_strnew(d_len + a_len)))
		return (NULL);
	if (dst)
	{
		new = ft_strcpy(new, dst);
		if (append)
			new = ft_strncat(new, append, a_len);
		ft_strdel(&dst);
	}
	else if (append)
		new = ft_strcpy(new, append);
	new[d_len + a_len] = '\0';
	dst = new;
	new = NULL;
	return (dst);
}
