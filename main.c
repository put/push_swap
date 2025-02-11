/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 17:20:19 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 01:30:32 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freeintarr(int **arr)
{
	int index = 0;

	while (arr[index])
		free(arr[index++]);
	free(arr);
}

int **argstoarr(int count, char **args)
{
	int **arr = calloc(count + 1, sizeof(int *));
	int index = 0;
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	while (index < count)
	{
		arr[index] = malloc(sizeof(int));
		if (!arr)
			return (freeintarr(arr), NULL);
		index++;
	}
	index = 0;
	while (index < count)
	{
		*(arr[index]) = atoi(args[index]);
		index++;
	}
	return (arr);
}

int check_dupes(int **arr)
{
	int i;
	int j;

	i = 0;
	while (arr && arr[i])
	{
		j = 0;
		while (arr && arr[j])
		{
			if (j != i && *(arr[j]) == *(arr[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_already_sorted(int **arr)
{
	int i;

	i = 0;
	while (arr && arr[i] && arr[i + 1])
	{
		if (*(arr[i]) >= *(arr[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

ps_list *arrtolst(int **arr)
{
	ps_list *first;
	ps_list *next;
	int index = 1;

	if (!arr || !(arr[0]))
		return (NULL);
	first = ps_lstnew(*(arr[0]));
	if (!first)
		return (NULL);
	while (arr[index])
	{
		next = ps_lstnew(*(arr[index++]));
		if (!next)
			return (ps_lstclear(&first), NULL);
		ps_lstadd_back(&first, next);
	}
	return (first);
}

void bubblesort(int **arr, int n)
{
	int i;
	int j;
	int *temp;

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

void normalize(int **tochange, int **tosort, int sz)
{
	int i;
	int j;

	bubblesort(tosort, sz);
	i = 0;
	while (i < sz)
	{
		j = 0;
		while (j < sz)
		{
			if (*(tosort[i]) == *(tochange[j]))
			{
				*(tochange[j]) = i;
				break;
			}
			j++;
		}
		i++;
	}
}

int getmaxbits(int lstsize)
{
	int bits;
	int valuecount;

	bits = 0;
	valuecount = lstsize;
	while ((valuecount >> bits) != 0)
		bits++;
	return (bits);
}

int radix_sort(ps_list **a, ps_list **b, int size, int bits)
{
	int bit;
	int sizecpy;
	int total;
	ps_list *curr;

	total = 0;
	bit = 0;
	while (bit < bits)
	{
		sizecpy = size;
		while (sizecpy--)
		{
			curr = *a;
			if ((curr->content >> bit) & 1)
				total += ra(a);
			else
				total += pb(a, b);
		}
		while (*b)
			total += pa(b, a);
		bit++;
	}
	return (total);
}


int main(int argc, char **argv)
{
	int **thing;
	int **tosort;
	ps_list *normlst;
	ps_list *b;
	
	if (argc < 2)
		return(ft_printf("Error\nInvalid number of arguments"));
	thing = argstoarr(argc - 1, argv + 1);
	if (!check_dupes(thing))
		return(ft_printf("Error\nDuplicates found"), 1);
	tosort = argstoarr(argc - 1, argv + 1);
	normalize(thing, tosort, argc - 1);
	normlst = arrtolst(thing);
	b = NULL;
	radix_sort(&normlst, &b, argc - 1, getmaxbits(argc - 1));
	b = normlst;
	ps_lstclear(&b);
	freeintarr(thing);
	freeintarr(tosort);
}
