/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:21:57 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:21:58 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	j = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
