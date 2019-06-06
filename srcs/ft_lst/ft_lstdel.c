/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:44:36 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/06 22:31:00 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list *alst, void (*del)(void *, size_t))
{
	t_node *ptr;

	if (alst)
	{
		if (alst->head && del)
		{
			while (alst->head)
			{
				ptr = alst->head;
				alst->head = alst->head->next;
				ft_node_del(&ptr, del);
			}
		}
		ft_bzero(alst, sizeof(*alst));
		ft_memdel((void**)&alst);
	}
}
