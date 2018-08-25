/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 21:26:56 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 21:45:24 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long number;
	long digit;
	long new;

	number = (long)n;
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number >= 10)
	{
		digit = number / 10;
		ft_putnbr(digit);
	}
	new = number % 10;
	ft_putchar(new + 48);
}
