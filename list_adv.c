/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_adv.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:41:56 by mika          #+#    #+#                 */
/*   Updated: 2025/02/10 17:31:22 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmplst;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmplst = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmplst;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

static t_list	*make_item(int content)
{
	t_list	*res;

	res = ft_lstnew(content);
	if (!res)
		return (NULL);
	return (res);
}

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*reslst;
	t_list	*tmplst;
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
			ft_lstclear(&reslst);
			return (NULL);
		}
		ft_lstadd_back(&reslst, tmplst);
		lst = lst->next;
	}
	return (reslst);
}
