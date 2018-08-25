/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 19:33:55 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 17:12:51 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		l;
	char	*str;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen((char*)s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		j++;
	}
	while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
		l--;
	if (l == 0)
		return (ft_strnew(1));
	if (!(str = ft_strnew(l - j)))
		return (NULL);
	str = ft_strsub(s, j, l - j);
	return (str);
}
