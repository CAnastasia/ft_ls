/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_list.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 19:56:13 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 20:05:39 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			open_dir_list(t_list_ls **second_tmp, char *filename,
			char **new_root, t_opt *options)
{
	t_stat	st;

	if (NULL == (options->fd = opendir(*new_root)))
	{
		if (lstat(filename, &st) < 0)
		{
			return (1);
		}
		if (S_ISREG(st.st_mode) || S_ISCHR(st.st_mode) || S_ISFIFO(st.st_mode)
			|| S_ISBLK(st.st_mode) || S_ISLNK(st.st_mode) ||
			S_ISSOCK(st.st_mode))
		{
			if (NULL == (*second_tmp = malloc((sizeof(**second_tmp)))))
				exit(EXIT_FAILURE);
			(*second_tmp)->name = filename;
			(options->opt_l == 1 ? file_info((*second_tmp)->name, filename,
			*options) : action_file(*second_tmp));
			free(*second_tmp);
			*second_tmp = NULL;
			return (1);
		}
	}
	return (0);
}

t_list_ls	*put_in_list(char *filename, char **new_root, t_opt options)
{
	t_list_ls	*tmp_list;
	t_list_ls	*second_tmp;

	second_tmp = NULL;
	if (NULL == (*new_root = malloc((ft_strlen(filename) + 2))))
		exit(EXIT_FAILURE);
	memcpy(*new_root, filename, ft_strlen(filename));
	(*new_root)[ft_strlen(filename)] = '/';
	(*new_root)[ft_strlen(filename) + 1] = '\0';
	if (open_dir_list(&second_tmp, filename, new_root, &options))
	{
		free(*new_root);
		return (second_tmp);
	}
	tmp_list = second_tmp;
	read_dir(&tmp_list, &second_tmp, options, *new_root);
	tmp_list = second_tmp;
	return (tmp_list);
}

void		display_list(t_list_ls *s1, t_opt options, char *filename)
{
	char	*new_name;

	while (s1)
	{
		if (options.opt_l == 1)
		{
			new_name = ft_strjoin(filename, s1->name);
			file_info(s1->name, new_name, options);
			free(new_name);
		}
		else
		{
			new_name = ft_strjoin(filename, s1->name);
			display_color(new_name);
			free(new_name);
			actions_dir(s1);
			if (s1->next == NULL)
				ft_putchar('\n');
			write(1, "\033[0m", 4);
		}
		s1 = s1->next;
	}
}

int			verif_opt(char *arg, char comp_char)
{
	int	ret;

	ret = 0;
	if (ft_strchr(arg, comp_char) != NULL)
		ret = 1;
	return (ret);
}

int			list_size(t_list_ls *s1)
{
	int	size;

	size = 0;
	while (s1 != NULL)
	{
		size++;
		s1 = s1->next;
	}
	return (size);
}
