/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   time_functions.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 20:43:21 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 21:03:23 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_year(t_stat file_stat)
{
	char	tmp[5];

	ft_memcpy(tmp, ctime(&(file_stat.st_mtime)) + 4, 4);
	tmp[4] = '\0';
	ft_putstr(tmp);
	ft_putchar(' ');
	ft_putchar(' ');
	ft_memcpy(tmp, ctime(&(file_stat.st_mtime)) + 8, 3);
	tmp[3] = '\0';
	ft_putstr(tmp);
	ft_memcpy(tmp, ctime(&(file_stat.st_mtime)) + 20, 4);
	tmp[4] = '\0';
	ft_putstr(tmp);
}

void	time_info(t_stat file_stat)
{
	char	tmp[9];
	time_t	seconds;

	seconds = time(NULL);
	if ((seconds - 15778463) < file_stat.st_mtime ||
		seconds < file_stat.st_mtime)
	{
		ft_memcpy(tmp, ctime(&(file_stat.st_mtime)) + 4, 4);
		tmp[4] = '\0';
		ft_putstr(tmp);
		ft_putchar(' ');
		ft_putchar(' ');
		ft_memcpy(tmp, ctime(&(file_stat.st_mtime)) + 8, 8);
		tmp[8] = '\0';
		ft_putstr(tmp);
	}
	else
	{
		display_year(file_stat);
	}
}

void	list_alloc(t_list_ls **n, t_dir *f, t_stat st, char *new_dir)
{
	free(new_dir);
	if (NULL == ((*n) = malloc((sizeof(**n)))))
		exit(EXIT_FAILURE);
	(*n)->name = ft_strdup(f->d_name);
	(*n)->modif_time = st.st_mtime;
	if (S_ISDIR(st.st_mode) && !(S_ISLNK(st.st_mode)))
		(*n)->is_dir = 1;
	else
		(*n)->is_dir = 0;
	(*n)->next = NULL;
}
