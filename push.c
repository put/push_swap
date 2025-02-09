/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:50:04 by mika          #+#    #+#                 */
/*   Updated: 2025/02/09 14:06:06 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

static int push(t_list **a, t_list **b)
{
	t_list *afirst;
	t_list *bfirst;

	if (!b || !a)
		return (0);
	afirst = *a;
	bfirst = *b;
	if (!bfirst)
		return (0);
	*b = bfirst->next;
	bfirst->next = afirst;
	*a = bfirst;
	return (1);
}

/**
 * Takes and removes first element from B, pushes to top of A
 * @param a List A
 * @param b List B
 * @returns 1 on success, 0 on failure
 */
int pa(t_list **a, t_list **b)
{
	return push(a, b);
}

/**
 * Takes and removes first element from A, pushes to top of B
 * @param b List B
 * @param a List A
 * @returns 1 on success, 0 on failure
 */
int pb(t_list **b, t_list **a)
{
	return (push(b, a));
}
