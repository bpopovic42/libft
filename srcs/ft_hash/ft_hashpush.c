/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:04:55 by bopopovi          #+#    #+#             */
/*   Updated: 2018/05/25 00:41:52 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashpush(t_hash **list, t_hash *elem)
{
	t_hash *ptr;

	ptr = *list;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = elem;
	}
	else
		*list = elem;
}
