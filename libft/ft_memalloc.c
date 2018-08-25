/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:20:29 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:38:14 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * size)) || size == 0)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
