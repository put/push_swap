/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:50:04 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 01:26:52 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int push(ps_list **src, ps_list **dest)
{
	ps_list *src_first;
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
int pa(ps_list **src, ps_list **dest)
{
	ft_printf("pa\n");
	return push(src, dest);
}

/**
 * Takes and removes first element from A, pushes to top of B
 * @param src List A
 * @param dest List B
 * @returns 1 on success, 0 on failure
 */
int pb(ps_list **src, ps_list **dest)
{
	ft_printf("pb\n");
	return (push(src, dest));
}
