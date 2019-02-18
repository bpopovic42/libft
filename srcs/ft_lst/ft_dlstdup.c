/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:00:50 by bopopovi          #+#    #+#             */
/*   Updated: 2019/02/18 21:04:38 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstdup(t_dlist **alst)
{
	t_dlist *ptr;
	t_dlist *dup;
	t_dlist *link_dup;

	ptr = *alst;
	dup = NULL;
	link_dup = NULL;
	while (ptr && ptr->next != *alst)
	{
		link_dup = ft_dlstnew(ptr->content, ptr->content_size);
		ft_dlstadd(&dup, link_dup);
		ptr = ptr->next;
	}
	return (dup);
}
