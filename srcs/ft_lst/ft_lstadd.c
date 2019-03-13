/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:09:56 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/13 21:11:20 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list *alst, t_node *new)
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
