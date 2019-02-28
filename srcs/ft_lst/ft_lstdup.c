/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:00:50 by bopopovi          #+#    #+#             */
/*   Updated: 2019/02/28 18:06:15 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list **alst)
{
	t_list *ptr;
	t_list *dup;
	t_list *link_dup;

	ptr = *alst;
	dup = NULL;
	link_dup = NULL;
	while (ptr && ptr->next != *alst)
	{
		link_dup = ft_lstnew(ptr->content, ptr->content_size);
		ft_lstadd(&dup, link_dup);
		ptr = ptr->next;
	}
	return (dup);
}
