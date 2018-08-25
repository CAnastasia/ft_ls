/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:20:15 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:34:36 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *point1;
	t_list *point2;

	if (*alst == NULL || alst == NULL)
		return ;
	point1 = *alst;
	while (point1)
	{
		point2 = point1->next;
		del(point1->content, point1->content_size);
		free(point1);
		point1 = point2;
	}
	*alst = NULL;
}
