/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:50:04 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 03:48:43 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_pslist **src, t_pslist **dest)
{
	t_pslist	*src_first;

	if (!src || !*src)
		return (0);
	src_first = *src;
	*src = src_first->next;
	src_first->next = *dest;
	*dest = src_first;
	return (1);
}

/**
 * Takes and removes first element from B, pushes to top of A
 * @param src List B
 * @param dest List A
 * @returns 1 on success, 0 on failure
 */
int	pa(t_pslist **src, t_pslist **dest)
{
	write(1, "pa\n", 3);
	return (push(src, dest));
}

/**
 * Takes and removes first element from A, pushes to top of B
 * @param src List A
 * @param dest List B
 * @returns 1 on success, 0 on failure
 */
int	pb(t_pslist **src, t_pslist **dest)
{
	write(1, "pb\n", 3);
	return (push(src, dest));
}
