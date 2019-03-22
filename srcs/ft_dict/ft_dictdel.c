/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:16:59 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/22 16:51:41 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dictdel(t_dict **elem, void (*del)(void **, size_t))
{
	(*elem)->key = 0;
	(*elem)->next = NULL;
	del(&(*elem)->data, (*elem)->data_size);
	(*elem)->data_size = 0;
	ft_memdel((void**)elem);
}
