/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:52:00 by bopopovi          #+#    #+#             */
/*   Updated: 2019/02/21 18:48:54 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter_data(t_dlist *dlst, void (*f)(void *content))
{
	while (dlst)
	{
		if (dlst && dlst->content)
			f(dlst->content);
		dlst = dlst->next;
	}
}
