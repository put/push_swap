/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 03:17:19 by mika              #+#    #+#             */
/*   Updated: 2025/02/12 18:44:39 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

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

int	ps_atoi(const char *nptr, int *err)
{
	long	sig;
	long	res;

	res = 0;
	sig = 1;
	*err = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		sig = (*nptr++ || res == 0);
	if (*nptr == 43 || *nptr == 45)
		sig = (*nptr++ - 44) * -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr++ - 48);
		if (res > INT_MAX)
			return ((int)res);
	}
	*err = 0;
	return ((int)(sig * res));
}

int	**argstoarr(int count, char **args)
{
	int	**arr;
	int	index;
	int	err;

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
		*(arr[index]) = ps_atoi(args[index], &err);
		if (err)
			return (freeintarr(arr), NULL);
		index++;
	}
	return (arr);
}
