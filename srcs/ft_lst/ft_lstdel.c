/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:44:36 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/15 20:18:13 by bopopovi         ###   ########.fr       */
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
		alst->head = NULL;
		alst->tail = NULL;
		alst->size = 0;
		free(alst);
		alst = NULL;
	}
}
