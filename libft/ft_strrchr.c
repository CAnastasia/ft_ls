/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:25:33 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 17:02:49 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	int			i;

	i = ft_strlen((char*)s);
	p = s + i;
	while (i >= 0)
	{
		if (*p == (char)c)
			return (char*)p;
		i--;
		p--;
	}
	return (NULL);
}
