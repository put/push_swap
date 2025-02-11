/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 02:03:24 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 03:48:43 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swaps the first and second elements of List A with each other
 * @param a List A
 * @returns 0 if fail, 1 if success
 */
int	sa(t_pslist **a)
{
	t_pslist	*temp;

	if (!a || !*a || !(*a)->next)
		return (0);
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	write(1, "sa\n", 3);
	return (1);
}
