/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:24:03 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:57:11 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(newstr = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1)))
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
