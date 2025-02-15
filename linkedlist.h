/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mika <mika@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/09 13:37:04 by mika          #+#    #+#                 */
/*   Updated: 2025/02/11 03:50:11 by mika          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct t_pslist
{
	int				content;
	struct t_pslist	*next;
}	t_pslist;

t_pslist	*ps_lstnew(int content);
void		ps_lstadd_back(t_pslist **lst, t_pslist *new);
t_pslist	*ps_lstlast(t_pslist *lst);
void		ps_lstclear(t_pslist **lst);
#endif
