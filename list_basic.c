/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_basic.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:36:19 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 01:26:52 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

ps_list	*ps_lstnew(int content)
{
	ps_list	*new;

	new = malloc(sizeof(ps_list));
	if (new == NULL)
		return (NULL);
	*new = (ps_list){content, NULL};
	return (new);
}

void	ps_lstadd_back(ps_list **lst, ps_list *new)
{
	ps_list	*lastlst;

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

void	ps_lstadd_front(ps_list **lst, ps_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ps_lstsize(ps_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

ps_list	*ps_lstlast(ps_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
