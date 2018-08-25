/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:23:42 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:55:26 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t k;
	size_t p;
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	k = ft_strlen((char*)src);
	p = ft_strlen(dest);
	if (size < ft_strlen(dest))
		return (size + ft_strlen((char*)src));
	while (dest[i] != '\0')
		i++;
	while (j < (size - p - 1) && i < size)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (p + k);
}
