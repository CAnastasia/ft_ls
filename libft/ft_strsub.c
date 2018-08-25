/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:03:55 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 17:09:59 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*newstr;

	i = 0;
	if (s == NULL || start > ft_strlen((char*)s))
		return (NULL);
	if (!(newstr = ft_strnew(len)))
		return (NULL);
	if (s)
	{
		while ((start < ft_strlen((char*)s)) && len--)
		{
			newstr[i] = s[start];
			i++;
			start++;
		}
		newstr[i] = '\0';
	}
	return (newstr);
}
