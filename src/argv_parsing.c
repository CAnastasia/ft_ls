/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   argv_parsing.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 19:35:29 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 19:39:46 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_file(int argc, char **argv)
{
	int		i;
	t_stat	st;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (lstat(argv[i], &st) == 0)
		{
			if (!S_ISDIR(st.st_mode))
			{
				count++;
			}
		}
		i++;
	}
	return (count);
}

int		count_dir(int argc, char **argv)
{
	int		i;
	t_stat	st;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (lstat(argv[i], &st) == 0)
		{
			if (S_ISDIR(st.st_mode))
			{
				count++;
			}
		}
		i++;
	}
	return (count);
}

char	**argv_file(int argc, char **argv, int size)
{
	int		i;
	int		j;
	char	**copy_argv;
	t_stat	st;

	i = 1;
	j = 0;
	if (!(copy_argv = (char**)malloc(sizeof(*copy_argv) * size)))
		return (NULL);
	while (i < argc)
	{
		if (lstat(argv[i], &st) == 0)
		{
			if (!S_ISDIR(st.st_mode))
			{
				if (j < size)
				{
					copy_argv[j] = ft_strdup(argv[i]);
					j++;
				}
			}
		}
		i++;
	}
	return (copy_argv);
}

char	**argv_folder(int argc, char **argv, int size)
{
	int		i;
	int		j;
	char	**copy_argv;
	t_stat	st;

	i = 1;
	j = 0;
	if (!(copy_argv = (char**)malloc(sizeof(*copy_argv) * size)))
		return (NULL);
	while (i < argc)
	{
		if (lstat(argv[i], &st) == 0)
		{
			if (S_ISDIR(st.st_mode))
			{
				if (j < size)
				{
					copy_argv[j] = ft_strdup(argv[i]);
					j++;
				}
			}
		}
		i++;
	}
	return (copy_argv);
}

char	**sort_argv(char **str, int size)
{
	char	*temp;
	int		i;
	int		j;
	char	**argv_to_sort;

	argv_to_sort = str;
	i = 0;
	while (i < size && (j = i + 1))
	{
		while (j < size)
		{
			if (ft_strcmp(argv_to_sort[i], argv_to_sort[j]) > 0)
			{
				temp = ft_strdup(argv_to_sort[i]);
				free(argv_to_sort[i]);
				argv_to_sort[i] = ft_strdup(argv_to_sort[j]);
				free(argv_to_sort[j]);
				argv_to_sort[j] = ft_strdup(temp);
				free(temp);
			}
			j++;
		}
		i++;
	}
	return (argv_to_sort);
}
