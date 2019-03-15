/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:09:56 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/15 20:16:57 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list *alst, t_node *new)
{
	if (alst)
	{
		new->next = alst->head;
		alst->head = new;
		if (alst->size == 0 && !alst->tail)
		{
			alst->tail = new;
			alst->size = 1;
		}
		else
			alst->size += 1;
	}
}
