/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:32:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/20 14:35:34 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*ptr;

	ptr = *alst;
	ptr->prev = 0;
	ptr->next = 0;
	del(ptr->content, ptr->content_size);
	ptr->content_size = 0;
	free(ptr->content);
	free(ptr);
}
