/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:15:29 by mika              #+#    #+#             */
/*   Updated: 2025/02/12 18:43:44 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_pslist **a, t_pslist **b, int size, int bits)
{
	int			bit;
	int			sizecpy;
	t_pslist	*curr;

	bit = 0;
	while (bit < bits)
	{
		sizecpy = size;
		while (sizecpy--)
		{
			curr = *a;
			if ((curr->content >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(b, a);
		bit++;
	}
}

void	sortthree(t_pslist **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sortfour(t_pslist **a, t_pslist **b, int min_pos)
{
	if (min_pos == 1)
		ra(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
	pb(a, b);
	sortthree(a);
	pa(b, a);
}

void	sortfive(t_pslist **a, t_pslist **b, int min_pos)
{
	if (min_pos == 1)
		ra(a);
	else if (min_pos == 2)
		ra2(a);
	else if (min_pos == 3)
		rra2(a);
	else if (min_pos == 4)
		rra(a);
	pb(a, b);
	min_pos = findlowest(*a);
	if (min_pos == 1)
		ra(a);
	else if (min_pos == 2)
		ra2(a);
	else if (min_pos == 3)
		rra(a);
	pb(a, b);
	sortthree(a);
	pa(b, a);
	pa(b, a);
}

void	bubblesort(int **arr, int n)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (*arr[j] > *arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
