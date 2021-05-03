/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:34:05 by bopopovi          #+#    #+#             */
/*   Updated: 2021/05/03 18:10:39 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cmp(void *a, void *b)
{
	int *int_a;
	int *int_b;

	int_a = (int*)a;
	int_b = (int*)b;
	return (*int_a < *int_b);
}

static void		print(t_node *node)
{
	int *integer;

	integer = (int*)node->data;
	ft_putnbr(*integer);
	ft_putchar(' ');
}

int				main(void)
{
	int		i;
	t_list	*new;

	i = 0;
	new = ft_lstnew();
	while (i < 10)
	{
		ft_lstadd_data(new, &i, sizeof(i));
		i++;
	}
	ft_lstiter(new, &print);
	ft_putchar('\n');
	ft_lstsort(new, &cmp);
	ft_lstiter(new, &print);
	return (0);
}
