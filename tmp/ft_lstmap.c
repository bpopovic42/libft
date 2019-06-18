/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:40:40 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/24 19:45:51 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *ptr;

	if (!(new = f(lst)))
		return (NULL);
	ptr = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ptr->next = f(lst)))
			return (NULL);
		ptr = ptr->next;
	}
	return (new);
}
