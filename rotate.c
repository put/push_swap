/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 14:06:43 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 03:48:43 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_pslist **list)
{
	t_pslist	*first;
	t_pslist	*last;

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

int	reverse_rotate(t_pslist **list)
{
	t_pslist	*last;
	t_pslist	*second_last;

	if (!list || !*list || !(*list)->next)
		return (0);
	last = *list;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *list;
	*list = last;
	return (1);
}

/**
 * Rotates list A. First element becomes the last, second becomes the first
 * @param a List A
 * @returns 0 if fail, 1 if success
 */
int	ra(t_pslist **a)
{
	write(1, "ra\n", 3);
	return (rotate(a));
}

/**
 * Reverse rotates list A. Last element becomes first,
 * and the first element becomes the second
 * @param a List A
 * @returns 0 if fail, 1 if success
 */
int	rra(t_pslist **a)
{
	write(1, "rra\n", 4);
	return (reverse_rotate(a));
}
