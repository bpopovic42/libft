/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:06:41 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/20 14:09:50 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist		*new;

	new = 0;
	if (!(new = malloc(sizeof(t_dlist))))
		return (NULL);
	new->prev = 0;
	new->next = 0;
	new->content = ft_memdup(content, content_size);
	new->content_size = content_size;
	return (new);
}
