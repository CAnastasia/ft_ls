/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 17:43:31 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 19:49:41 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*var;

	if (!(var = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		var->content = NULL;
		var->content_size = 0;
	}
	else
	{
		if (!(var->content = malloc(content_size)))
			return (NULL);
		var->content = ft_memcpy(var->content, content, content_size);
		var->content_size = content_size;
	}
	var->next = NULL;
	return (var);
}
