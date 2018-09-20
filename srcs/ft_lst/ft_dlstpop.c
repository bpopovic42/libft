/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:01:06 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/20 15:11:52 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstpop(t_dlist **head)
{
	t_dlist		*tmp;

	tmp = NULL;
	if (head && *head)
	{
		tmp = *head;
		*head = tmp->next;
		if (*head)
			(*head)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}
