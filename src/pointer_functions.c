/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pointer_functions.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 20:16:49 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 20:18:26 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		compare_alphabetic(t_list_ls *first, t_list_ls *second)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(first->name, second->name) < 0)
		ret = 1;
	return (ret);
}

int		compare_time(t_list_ls *first, t_list_ls *second)
{
	int	ret;

	ret = 0;
	if (first->modif_time > second->modif_time)
		ret = 1;
	else if (first->modif_time == second->modif_time)
	{
		if (compare_alphabetic(first, second))
			ret = 1;
	}
	return (ret);
}

int		compare_alphabetic_reverse(t_list_ls *first, t_list_ls *second)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(first->name, second->name) > 0)
		ret = 1;
	return (ret);
}

int		compare_time_reverse(t_list_ls *first, t_list_ls *second)
{
	int	ret;

	ret = 0;
	if (first->modif_time < second->modif_time)
	{
		ret = 1;
	}
	else if (first->modif_time == second->modif_time)
	{
		if (compare_alphabetic_reverse(first, second))
			ret = 1;
	}
	return (ret);
}
