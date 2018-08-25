/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 20:11:51 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 20:16:30 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putnbr_long(long n)
{
	long	number;
	long	digit;
	long	new_nr;

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
	new_nr = number % 10;
	ft_putchar(new_nr + 48);
}

void	call_files(char **file_names, int size, t_opt opt)
{
	int	i;

	i = 0;
	while (i < opt.size_files)
	{
		recursive_dir(file_names[i], opt);
		if (i == size - 1)
			ft_putchar('\n');
		else if (opt.opt_l == 0)
			ft_putchar(' ');
		i++;
	}
}

void	call_folders(char **folder_names, int size, t_opt opt)
{
	int	i;

	i = 0;
	while (i < size)
	{
		recursive_dir(folder_names[i], opt);
		if (i < size - 1)
			ft_putchar('\n');
		i++;
	}
}

void	free_argv(char **folder, char **files, t_opt opt)
{
	int	i;

	i = 0;
	if (opt.size_files > 0)
	{
		while (i < opt.size_files)
		{
			free(files[i]);
			i++;
		}
	}
	free(files);
	i = 0;
	if (opt.size_argv > 0)
	{
		while (i < opt.size_argv)
		{
			free(folder[i]);
			i++;
		}
	}
	free(folder);
}

int		main(int argc, char **argv)
{
	t_opt	opt;
	char	**folders;
	char	**files;
	int		p;

	opt = (t_opt) {.opt_a = 0, .opt_l = 0, .opt_r_up = 0, .opt_r = 0,
		.opt_t = 0, .opt_b = 0, .opt_o = 0, .opt_g = 0};
	error_opt(argv);
	p = options(&opt, argv);
	opt.size_argv = count_dir(argc, argv);
	opt.size_files = count_file(argc, argv);
	folders = argv_folder(argc, argv, opt.size_argv);
	files = argv_file(argc, argv, opt.size_files);
	opt.argv_name = sort_argv(folders, opt.size_argv);
	opt.argv_files = sort_argv(files, opt.size_files);
	if ((opt.size_files == 0 && opt.size_argv == 0))
	{
		if (argc == 1 || p == 2)
			recursive_dir(".", opt);
	}
	call_files(opt.argv_files, opt.size_files, opt);
	(opt.size_files > 0 && opt.size_argv > 0) ? ft_putchar('\n') : p;
	call_folders(opt.argv_name, opt.size_argv, opt);
	free_argv(folders, files, opt);
	return (0);
}
