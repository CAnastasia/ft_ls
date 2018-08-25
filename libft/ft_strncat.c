/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:24:32 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 17:35:11 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0' && n--)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
