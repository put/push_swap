/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:36:19 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 03:48:43 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_pslist	*ps_lstnew(int content)
{
	t_pslist	*new;

	new = malloc(sizeof(t_pslist));
	if (new == NULL)
		return (NULL);
	*new = (t_pslist){content, NULL};
	return (new);
}

void	ps_lstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist	*lastlst;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lastlst = ps_lstlast(*lst);
	lastlst->next = new;
}

t_pslist	*ps_lstlast(t_pslist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ps_lstdelone(t_pslist *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ps_lstclear(t_pslist **lst)
{
	t_pslist	*tmplst;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmplst = (*lst)->next;
		ps_lstdelone(*lst);
		*lst = tmplst;
	}
	*lst = NULL;
}
