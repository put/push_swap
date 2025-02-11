/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 03:13:15 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 03:48:43 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arrlen(char **arr)
{
	int	count;

	count = 0;
	while (arr && arr[count])
		count++;
	return (count);
}

int	err(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	findlowest(t_pslist *list)
{
	int	current_pos;
	int	lowest_pos;
	int	lowest_val;

	current_pos = 0;
	lowest_pos = 1;
	while (list && list->next)
	{
		if (current_pos == 0)
		{
			current_pos = 1;
			lowest_val = list->content;
		}
		if (lowest_val > list->next->content)
		{
			lowest_pos = current_pos + 1;
			lowest_val = list->next->content;
		}
		current_pos++;
		list = list->next;
	}
	return (lowest_pos);
}

int	getmaxbits(int lstsize)
{
	int	bits;
	int	valuecount;

	bits = 0;
	valuecount = lstsize;
	while ((valuecount >> bits) != 0)
		bits++;
	return (bits);
}

int	check_already_sorted(int **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i] && arr[i + 1])
	{
		if (*(arr[i]) >= *(arr[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
