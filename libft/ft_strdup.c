/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:22:56 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 19:09:27 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strdup(void *src)
{
	char	*str;
	char	*s;
	int		i;
	int		n;

	str = (char*)src;
	i = 0;
	n = ft_strlen(str);
	if (!(s = (char*)malloc(sizeof(*s) * n + 1)))
		return (NULL);
	while (i < n)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
