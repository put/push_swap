/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:20:19 by mika              #+#    #+#             */
/*   Updated: 2025/02/13 18:52:57 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	fa(void **arr)
{
	int	index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

void	freeall(t_pslist **lst, int **one, int **two, char **three)
{
	ps_lstclear(lst);
	fa((void **)one);
	fa((void **)two);
	fa((void **)three);
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

	if (argc < 2)
		return (0);
	args = getargs(argc, argv);
	if (!args)
		return (err());
	arr = argstoarr(arrlen(args), args);
	if (!arr)
		return (fa((void **)args), err());
	tosort = argstoarr(arrlen(args), args);
	if (!tosort || !check_dupes(arr))
		return (fa((void **)arr), fa((void **)tosort),
			fa((void **)args), err());
	if (check_already_sorted(arr))
		return (fa((void **)arr), fa((void **)tosort), fa((void **)args), 0);
	normalize(arr, tosort, arrlen(args));
	normlst = arrtolst(arr);
	b = NULL;
	ps_sort(&normlst, &b, arrlen(args), getmaxbits(arrlen(args)));
	freeall(&normlst, arr, tosort, args);
}
