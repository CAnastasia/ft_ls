/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:15:39 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 17:02:19 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t j;
	size_t i;

	if (*needle == '\0')
		return ((char*)haystack);
	if (!(*haystack) || !(*needle))
		return (NULL);
	if (*haystack == '\0')
		return (NULL);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && (i + j) < len)
		{
			j++;
			if (j == ft_strlen((char*)needle))
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
