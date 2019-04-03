/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 06:06:58 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/03 06:18:06 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop_data(t_list *list)
{
	t_node	*ptr;
	void	*data_ptr;

	ptr = ft_lstpop(list);
	data_ptr = ptr->data;
	ft_node_del(&ptr, NULL);
	return (data_ptr);
}
