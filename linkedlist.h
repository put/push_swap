/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:37:04 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 01:27:14 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct ps_list
{
	int				content;
	struct ps_list	*next;
}	ps_list;

ps_list	*ps_lstnew(int content);
void	ps_lstadd_back(ps_list **lst, ps_list *new);
void	ps_lstadd_front(ps_list **lst, ps_list *new);
int		ps_lstsize(ps_list *lst);
ps_list	*ps_lstlast(ps_list *lst);
void	ps_lstclear(ps_list **lst);
#endif
