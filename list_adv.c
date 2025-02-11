/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_adv.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:41:56 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 01:26:52 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ps_lstdelone(ps_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ps_lstclear(ps_list **lst)
{
	ps_list	*tmplst;

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

void	ps_lstiter(ps_list *lst, void (*f)(int))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

static ps_list	*make_item(int content)
{
	ps_list	*res;

	res = ps_lstnew(content);
	if (!res)
		return (NULL);
	return (res);
}

ps_list	*ps_lstmap(ps_list *lst, int (*f)(int))
{
	ps_list	*reslst;
	ps_list	*tmplst;
	int		content;

	if (!lst || !f)
		return (NULL);
	content = f(lst->content);
	reslst = make_item(content);
	if (!reslst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		tmplst = make_item(content);
		if (!tmplst)
		{
			ps_lstclear(&reslst);
			return (NULL);
		}
		ps_lstadd_back(&reslst, tmplst);
		lst = lst->next;
	}
	return (reslst);
}
