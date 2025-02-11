/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 17:20:19 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 03:51:28 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeintarr(int **arr)
{
	int	index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

void	freestrarr(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

int	check_dupes(int **arr)
{
	int	i;
	int	j;

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

void	ps_sort(t_pslist **a, t_pslist **b, int size, int bits)
{
	if (size <= 1)
		return ;
	else if (size == 2)
		sa(a);
	else if (size == 3)
		sortthree(a);
	else if (size == 4)
		sortfour(a, b, findlowest(*a));
	else if (size == 5)
		sortfive(a, b, findlowest(*a));
	else
		radix_sort(a, b, size, bits);
}

int	main(int argc, char **argv)
{
	int			**arr;
	int			**tosort;
	char		**args;
	t_pslist	*normlst;
	t_pslist	*b;

	if (argc != 2)
		return (err());
	args = ft_split(argv[1], ' ');
	if (!args)
		return (err());
	arr = argstoarr(arrlen(args), args);
	tosort = argstoarr(arrlen(args), args);
	if (!arr || !tosort || !check_dupes(arr) || check_already_sorted(arr))
		return (freeintarr(arr), freeintarr(tosort), freestrarr(args), err());
	normalize(arr, tosort, arrlen(args));
	normlst = arrtolst(arr);
	b = NULL;
	ps_sort(&normlst, &b, arrlen(args), getmaxbits(arrlen(args)));
	ps_lstclear(&normlst);
	freeintarr(arr);
	freeintarr(tosort);
	freestrarr(args);
}
