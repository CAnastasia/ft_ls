/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:21:22 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:43:38 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s1;
	char		*s2;

	s1 = src;
	s2 = dest;
	if (s1 <= s2)
	{
		s1 += n - 1;
		s2 += n - 1;
		while (n--)
		{
			*s2-- = *s1--;
		}
	}
	else
	{
		ft_memcpy(dest, (unsigned char *)src, n);
	}
	return (dest);
}
