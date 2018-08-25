/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recursion.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 20:18:50 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 20:37:20 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_dir(t_list_ls **s1, t_list_ls **names, t_opt opt,
		char *dirname)
{
	t_stat		st;
	t_dir		*f;
	t_list_ls	*n;
	char		*new_dir;
	char		*dir_2;

	if (opt.fd == NULL)
		permission_error(dirname);
	else
	{
		while ((f = readdir(opt.fd)) != NULL)
		{
			new_dir = ft_strdup(dirname);
			dir_2 = new_dir;
			if (opt.opt_a == 1 || f->d_name[0] != '.')
			{
				new_dir = ft_strjoin(new_dir, f->d_name);
				lstat(new_dir, &st);
				list_alloc(&n, f, st, new_dir);
				find_dir(n, s1, names);
			}
			free(dir_2);
		}
		closedir(opt.fd);
	}
}

void	find_dir(t_list_ls *n, t_list_ls **s1, t_list_ls **names)
{
	if (*s1)
	{
		(*s1)->next = n;
		*s1 = n;
	}
	else
	{
		*names = n;
		*s1 = n;
	}
}

void	recursive_call(t_list_ls *s1, char *new_root, t_opt options)
{
	char	*tmp_dir;
	char	*dirtemp;

	while (s1)
	{
		if (s1->is_dir)
		{
			dirtemp = strdup(new_root);
			tmp_dir = dirtemp;
			dirtemp = ft_strjoin(new_root, (char*)s1->name);
			free(tmp_dir);
			if (options.opt_r_up == 1)
			{
				if ((dirtemp[ft_strlen(dirtemp) - 2] != '.' &&
					dirtemp[ft_strlen(dirtemp) - 1] != '.') ||
					dirtemp[ft_strlen(dirtemp) - 1] != '.')
				{
					ft_putchar('\n');
					recursive_dir(dirtemp, options);
				}
			}
			free(dirtemp);
		}
		s1 = s1->next;
	}
}

void	free_list(t_list_ls *names)
{
	t_list_ls	*prev;

	while (names != NULL)
	{
		prev = NULL;
		free(names->name);
		prev = names;
		names = names->next;
		free(prev);
	}
}

int		recursive_dir(char *dirname, t_opt options)
{
	t_list_ls	*names;
	t_list_ls	*s1;
	char		*new_root;

	names = NULL;
	if (((names = put_in_list(dirname, &new_root, options)) == NULL) &&
		((options.fd = opendir(dirname)) == NULL))
		return (1);
	if (options.fd != NULL)
		closedir(options.fd);
	merge_sort(&names, options);
	s1 = names;
	action_dir_pre(dirname, s1, &options);
	s1 = names;
	display_list(s1, options, new_root);
	recursive_call(s1, new_root, options);
	free(new_root);
	free_list(names);
	return (0);
}
