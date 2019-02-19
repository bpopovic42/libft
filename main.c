/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:34:43 by bopopovi          #+#    #+#             */
/*   Updated: 2019/02/19 19:51:52 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void print_dlist(t_dlist *list)
{
	t_dlist *ptr = list;
	while (ptr != NULL)
	{
		ft_putstr(ptr->content);
		ptr = ptr->next;
	}
}

// we need a specific deletion function to de-reference the dlists heads
// since we stored pointers to their addresses
// and that ft_dlstdel expect this address as well but is passed a pointer
// to the data contained in the vector (that is pointer on the stored pointer
// to the address of our list's heads)
static void vector_del(void **data)
{
	t_dlist **tmp = *data;
	ft_dlstdel((t_dlist**)tmp, (void*)&ft_strdel);
}

int main(void)
{
	int i = 0;
	t_dlist *test = NULL;
	t_dlist *test2 = NULL;
	// Put some random stuff in test and test2 dlists
	while (i < 3)
	{
		ft_dlstadd(&test, ft_dlstnew("toto\n", sizeof(char*)));
		ft_dlstadd(&test2, ft_dlstnew("titi\n", sizeof(char*)));
		i++;
	}
	// duplicate content of test into new
	t_dlist *new = ft_dlstdup(&test);
	//prints the dlists
	print_dlist(test);
	print_dlist(test2);
	print_dlist(new);
	// create a new vector to store test and test2
	t_vect *vector = ft_vector_init(sizeof(t_dlist**), 0);
	ft_vector_append(vector, &test);
	ft_vector_append(vector, &test2);
	// deletes test and test2
	ft_dlstdel(&test, (void*)&ft_strdel);
	ft_dlstdel(&test2, (void*)&ft_strdel);
	// clean the vector since dlists are already freed
	// works both ways since we appended those lists by passing their addresses
	ft_vector_free(vector, (void*)&vector_del);
	// deletes new which wasn't stored in the vector
	ft_dlstdel(&new, (void*)&ft_strdel);
	// none of those should be printed
	if (new)
		ft_putstr("new ok");
	if (test)
		ft_putstr("test ok");
	if (test2)
		ft_putstr("test2 ok");
	return (0);
}
