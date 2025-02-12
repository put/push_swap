/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:50:04 by mika              #+#    #+#             */
/*   Updated: 2025/02/12 18:52:46 by mschippe         ###   ########.fr       */
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

void	pa(t_pslist **src, t_pslist **dest)
{
	write(1, "pa\n", 3);
	push(src, dest);
}

void	pb(t_pslist **src, t_pslist **dest)
{
	write(1, "pb\n", 3);
	push(src, dest);
}
