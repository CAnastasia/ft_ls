/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:18:56 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:28:56 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int number;
	int i;
	int y;

	number = 0;
	i = 0;
	y = 1;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t') ||
			(str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		y *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			number = number * 10 + str[i] - 48;
		}
		else
			return (number * y);
		i++;
	}
	return (number * y);
}
