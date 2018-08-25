/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 20:37:30 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 20:42:45 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_list_ls	*sorted_lists(t_list_ls *first, t_list_ls *second,
			int (*compare)(t_list_ls *first, t_list_ls *second))
{
	t_list_ls	*res;

	res = 0;
	if (first == NULL)
		return (second);
	else if (second == NULL)
		return (first);
	if (compare(first, second))
	{
		res = first;
		res->next = sorted_lists(first->next, second, compare);
	}
	else
	{
		res = second;
		res->next = sorted_lists(first, second->next, compare);
	}
	return (res);
}

void		front_back_split(t_list_ls *source, t_list_ls **front,
			t_list_ls **back)
{
	t_list_ls	*fast;
	t_list_ls	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

void		merge_sort(t_list_ls **list, t_opt options)
{
	t_list_ls	*tmp;
	t_list_ls	*first;
	t_list_ls	*second;

	tmp = *list;
	if ((tmp == NULL) || (tmp->next == NULL))
		return ;
	front_back_split(tmp, &first, &second);
	merge_sort(&first, options);
	merge_sort(&second, options);
	if (options.opt_t && !options.opt_r)
		*list = sorted_lists(first, second, compare_time);
	else if (options.opt_t && options.opt_r)
		*list = sorted_lists(first, second, compare_time_reverse);
	else if (options.opt_r)
		*list = sorted_lists(first, second, compare_alphabetic_reverse);
	else
		*list = sorted_lists(first, second, compare_alphabetic);
}
