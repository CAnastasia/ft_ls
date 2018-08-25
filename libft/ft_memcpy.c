/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:21:09 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 20:26:16 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s1;
	char		*s2;
	size_t		i;

	s1 = src;
	s2 = dest;
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
