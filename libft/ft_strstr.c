/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:26:02 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 17:07:41 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int j;

	if (!(*s2))
		return ((char*)s1);
	j = ft_strlen((char*)s2);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, j) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
