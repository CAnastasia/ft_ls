/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:19:56 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 17:27:30 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_chiffre(long n)
{
	int i;

	i = 0;
	if (n > -10 && n < 10)
		return (1);
	while ((n = n / 10))
	{
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		div;
	int		neg;
	long	nr;

	nr = (long)n;
	neg = nr >= 0 ? 0 : 1;
	i = n >= 0 ? ft_count_chiffre(n) : ft_count_chiffre(n) + neg;
	nr = nr < 0 ? -nr : nr;
	div = 1;
	if (!(str = malloc(sizeof(char) * ft_count_chiffre(nr) + neg + 1)))
		return (NULL);
	str[ft_count_chiffre(nr) + neg] = '\0';
	if (neg == 1)
		i++;
	i = n < 0 ? i - 1 : i;
	while (i--)
	{
		str[i] = nr / div % 10 + '0';
		div *= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
