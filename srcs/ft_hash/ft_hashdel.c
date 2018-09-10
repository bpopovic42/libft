/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:16:59 by bopopovi          #+#    #+#             */
/*   Updated: 2018/05/25 00:24:53 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashdel(t_hash **elem)
{
	(*elem)->key = 0;
	(*elem)->data_size = 0;
	(*elem)->next = NULL;
	ft_memdel(&(*elem)->data);
	ft_memdel((void*)elem);
}
