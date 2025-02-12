/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschippe <mschippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:29:37 by mika              #+#    #+#             */
/*   Updated: 2025/02/12 18:48:15 by mschippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "linkedlist.h"
# include <unistd.h>

void		pa(t_pslist **src, t_pslist **dest);
void		pb(t_pslist **src, t_pslist **dest);
void		ra(t_pslist **a);
void		rra(t_pslist **a);
void		ra2(t_pslist **a);
void		rra2(t_pslist **a);
void		sa(t_pslist **a);
int			ps_atoi(const char *nptr, int *err);
t_pslist	*arrtolst(int **arr);
void		normalize(int **tochange, int **tosort, int sz);
int			**argstoarr(int count, char **args);
int			ft_atoi(const char *nptr);
void		ps_sort(t_pslist **a, t_pslist **b, int size, int bits);
int			check_dupes(int **arr);
void		freeintarr(int **arr);
int			arrlen(char **arr);
int			err(void);
int			findlowest(t_pslist *list);
int			getmaxbits(int lstsize);
int			check_already_sorted(int **arr);
void		radix_sort(t_pslist **a, t_pslist **b, int size, int bits);
void		sortthree(t_pslist **a);
void		sortfour(t_pslist **a, t_pslist **b, int min_pos);
void		sortfive(t_pslist **a, t_pslist **b, int min_pos);
void		bubblesort(int **arr, int n);
char		**ft_split(char const *s, char c);
#endif