/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 17:20:19 by mika          #+#    #+#                 */
/*   Updated: 2025/02/10 18:35:09 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linkedlist.h"
#include <stdio.h>

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

t_list *arrtolst(int **arr)
{
	t_list *first;
	t_list *next;
	int index = 1;

	if (!arr || !(arr[0]))
		return (NULL);
	first = ft_lstnew(*(arr[0]));
	if (!first)
		return (NULL);
	while (arr[index])
	{
		next = ft_lstnew(*(arr[index++]));
		if (!next)
			return (ft_lstclear(&first), NULL);
		ft_lstadd_back(&first, next);
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

int main(int argc, char **argv)
{
	int index = 0;
	if (argc < 2) return (1);
	int **thing = argstoarr(argc - 1, argv + 1);
	int **tosort = argstoarr(argc - 1, argv + 1);
	normalize(thing, tosort, argc - 1);
	while (thing[index])
		printf("%d\n", *(thing[index++]));
	freeintarr(thing);
	freeintarr(tosort);
}
