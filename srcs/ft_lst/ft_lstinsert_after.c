/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:07:48 by bopopovi          #+#    #+#             */
/*   Updated: 2021/05/03 18:08:24 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert_after(t_list *src, t_node *dest)
{
	t_node *src_list_tail;

	src_list_tail = ft_lstget_tail(src);
	src_list_tail->next = dest->next;
	dest->next = src->head;
}
