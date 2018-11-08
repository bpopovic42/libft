/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:01:06 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 23:02:56 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstpop(t_dlist *elem)
{
	if (elem)
	{
		if (elem->next)
			elem->next->prev = elem->prev;
		if (elem->prev)
			elem->prev->next = elem->next;
		elem->next = NULL;
		elem->prev = NULL;
	}
	return (elem);
}
