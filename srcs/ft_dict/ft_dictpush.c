/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:04:55 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 20:16:22 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dictpush(t_dict **list, t_dict *elem)
{
	t_dict *ptr;

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
