/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 21:05:51 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 18:37:11 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		number_of_words(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			j++;
	}
	return (j);
}

static int		nr_of_char(char const *str, char c, int *i)
{
	int j;

	j = 0;
	while (str[*i] == c)
		(*i)++;
	while (str[*i] != c && str[*i] != '\0')
	{
		(*i)++;
		j++;
	}
	return (j);
}

static char		*final_tab(char *dest, char const *src, char c)
{
	int i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		m;
	int		p;
	char	**str;

	i = 0;
	j = 0;
	m = 0;
	if (!s)
		return (NULL);
	m = number_of_words(s, c);
	if (!(str = (char**)malloc(sizeof(*str) * m + 1)))
		return (NULL);
	str[m] = 0;
	while (i < m)
	{
		p = nr_of_char(s, c, &j);
		if (!(str[i] = (char*)malloc(sizeof(*str) * p + 1)))
			return (NULL);
		str[i] = final_tab(str[i], &s[j - p], c);
		i++;
	}
	return (str);
}
