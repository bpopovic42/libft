/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:53:53 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/13 20:33:53 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_node(t_list *alst, t_node *node)
{
	if (alst->head == NULL)
	{
		alst->head = node;
		alst->tail = node;
		alst->size = 1;
	}
	else if (alst->tail != NULL)
	{
		alst->tail->next = node;
		alst->tail = alst->tail->next;
	}
}
