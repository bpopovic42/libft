/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:53:53 by bopopovi          #+#    #+#             */
/*   Updated: 2018/05/01 22:34:54 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alist, t_list *list)
{
	t_list	*ptr;

	if (*alist == NULL)
		*alist = list;
	else
	{
		ptr = *alist;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = list;
	}
}
