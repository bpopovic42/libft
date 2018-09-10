/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:44:36 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/23 16:31:01 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *ptr;

	lst = *alst;
	while (lst)
	{
		ptr = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = ptr;
	}
	*alst = NULL;
}
