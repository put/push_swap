/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:06:43 by mika              #+#    #+#             */
/*   Updated: 2025/02/12 18:52:25 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pslist **list)
{
	t_pslist	*first;
	t_pslist	*last;

	write(1, "ra\n", 3);
	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	*list = first->next;
	first->next = NULL;
	last = *list;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rra(t_pslist **list)
{
	t_pslist	*last;
	t_pslist	*second_last;

	write(1, "rra\n", 4);
	if (!list || !*list || !(*list)->next)
		return ;
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
	return ;
}

void	ra2(t_pslist **a)
{
	ra(a);
	ra(a);
}

void	rra2(t_pslist **a)
{
	rra(a);
	rra(a);
}
