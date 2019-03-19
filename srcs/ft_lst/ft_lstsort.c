/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:40:39 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/19 19:41:03 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_node *ft_node_get_tail(t_node *node)
{
	t_node *tail;

	tail = node;
	while (tail && tail->next)
		tail = tail->next;
	return (tail);
}

static void		move_node_to_end(t_node **current, t_node **prev, t_node **end)
{
	t_node *tmp;

	tmp = (*current)->next;
	if (*prev)
		(*prev)->next = (*current)->next;
	(*current)->next = NULL;
	(*end)->next = *current;
	*end = *current;
	*current = tmp;
}

static t_node	*get_pivot(t_node *head, t_node *tail, t_list *new,
		int (*cmp)(void*, void*))
{
	t_node *pivot;
	t_node *current;
	t_node *previous;
	t_node *end;

	pivot = tail;
	current = head;
	previous = NULL;
	end = pivot;
	while (current != pivot)
	{
		if (cmp(current->data, pivot->data))
		{
			if (new->head == NULL)
				new->head = current;
			previous = current;
			current = current->next;
		}
		else
			move_node_to_end(&current, &previous, &end);
	}
	if (new->head == NULL)
		new->head = pivot;
	new->tail = end;
	return (pivot);
}

static t_node	*lst_qsort(t_node *head, t_node *tail, int (*cmp)(void*, void*))
{
	t_node	*pivot;
	t_list	new;
	t_node	*tmp;

	pivot = NULL;
	new.size = 0;
	new.tail = NULL;
	new.head = NULL;
	tmp = NULL;
	if (!head || head == tail)
		return (head);
	pivot = get_pivot(head, tail, &new, cmp);
	if (new.head != pivot)
	{
		tmp = new.head;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		new.head = lst_qsort(new.head, tmp, cmp);
		tmp = ft_node_get_tail(new.head);
		tmp->next = pivot;
	}
	pivot->next = lst_qsort(pivot->next, new.tail, cmp);
	return (new.head);
}

void			ft_lstsort(t_list *alst, int (*cmp)(void*, void*))
{
	alst->head = lst_qsort(alst->head, alst->tail, cmp);
}
