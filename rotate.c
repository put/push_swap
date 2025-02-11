/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 14:06:43 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 01:26:52 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotate(ps_list **list)
{
	ps_list *first;
	ps_list *last;

	if (!list || !*list || !(*list)->next)
		return (0);
	first = *list;
	*list = first->next;
	first->next = NULL;
	last = *list;
	while (last->next)
		last = last->next;
	last->next = first;
	return (1);
}

/**
 * Rotates list A. First element becomes the last, second becomes the first
 * @param a List A
 * @returns 0 if fail, 1 if success
 */
int	ra(ps_list **a)
{
	ft_printf("ra\n");
	return (rotate(a));
}
