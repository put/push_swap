/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 17:20:19 by mika          #+#    #+#                 */
/*   Updated: 2025/02/10 17:32:46 by mika          ########   odam.nl         */
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

int main(int argc, char **argv)
{
	if (argc < 2) return (1);
	int index = 0;
	int **thing = argstoarr(argc - 1, argv + 1);
	while (thing[index])
		printf("%d\n", *(thing[index++]));
	freeintarr(thing);
}
