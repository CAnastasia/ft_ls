/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 23:20:39 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:36:44 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;

	if (!lst)
		return (NULL);
	if (!(tmp = (t_list*)malloc(sizeof(lst))))
		return (NULL);
	tmp = f(lst);
	tmp->next = ft_lstmap(lst->next, f);
	return (tmp);
}
