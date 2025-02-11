/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 03:17:19 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 03:49:30 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*arrtolst(int **arr)
{
	t_pslist	*first;
	t_pslist	*next;
	int			index;

	index = 1;
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

void	normalize(int **tochange, int **tosort, int sz)
{
	int	i;
	int	j;

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
				break ;
			}
			j++;
		}
		i++;
	}
}

int	**argstoarr(int count, char **args)
{
	int	**arr;
	int	index;

	arr = calloc(count + 1, sizeof(int *));
	index = 0;
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

int	ft_atoi(const char *nptr)
{
	long	sig;
	long	res;

	res = 0;
	sig = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		sig = (*nptr++ || res == 0);
	if (*nptr == 43 || *nptr == 45)
		sig = (*nptr++ - 44) * -1;
	while (*nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*nptr++ - 48);
	return ((int)(sig * res));
}
