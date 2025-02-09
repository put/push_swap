/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 14:06:43 by mika          #+#    #+#                 */
/*   Updated: 2025/02/09 14:25:53 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

int	rotate(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;
	t_list	*prev;

	if (!list || !*list || !(*list)->next)
		return (0);
	first = *list;
	second = first->next;
	last = first;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = first;
	first->next = NULL;
	*list = second;
	return (1);
}

int	ra(t_list **a)
{
	return (rotate(a));
}

int	rb(t_list **b)
{
	return (rotate(b));
}

int	rr(t_list **a, t_list **b)
{
	if ((!a || !*a || !(*a)->next) || (!b || !*b || !(*b)->next))
		return (0);
	rotate(a);
	rotate(b);
	return (1);
}

