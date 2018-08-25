/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   actions_file_folder.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 18:39:06 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 19:26:27 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_nb_col(void)
{
	t_winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return ((int)w.ws_col);
}

void	actions_dir(t_list_ls *dir)
{
	static int	line = 0;
	static int	length;
	int			test;

	test = 0;
	length = ft_nb_col();
	line += (ft_strlen(dir->name) + 3);
	if (dir->next)
		test = (ft_strlen(dir->next->name) + 4);
	if (line + test > length)
	{
		write(1, "\n", 1);
		line = 0;
	}
	if (dir->next == NULL)
		line = 0;
	write(1, dir->name, ft_strlen(dir->name));
	write(1, "   ", 3);
}

void	action_dir_pre(char *root, t_list_ls *s1, t_opt *options)
{
	if (check_same_name(root, *options) || options->size_files > 0)
	{
		ft_putstr(root);
		ft_putchar(':');
		ft_putchar('\n');
	}
	if (options->opt_l)
	{
		if (s1 != NULL)
			function_total(root, s1, *options);
		max_nr(root, s1, options);
		max_gid_uid(root, s1, options);
	}
}

void	action_file(t_list_ls *file)
{
	display_color(file->name);
	write(1, file->name, ft_strlen(file->name));
	write(1, "\033[0m", 4);
}

void	display_color(char *directory)
{
	t_stat	file_stat;

	if (lstat(directory, &file_stat) < 0)
		return ;
	if (S_ISLNK(file_stat.st_mode))
		write(1, "\033[1;34m", 7);
	if (S_ISFIFO(file_stat.st_mode))
		write(1, "\033[0;33m", 7);
	if (S_ISBLK(file_stat.st_mode))
		write(1, "\033[0;32m", 7);
	if (S_ISCHR(file_stat.st_mode))
		write(1, "\033[0;31m", 7);
	if (S_ISSOCK(file_stat.st_mode))
		write(1, "\033[0;35m", 7);
	if (S_ISDIR(file_stat.st_mode))
		write(1, "\033[0;36m", 7);
}
