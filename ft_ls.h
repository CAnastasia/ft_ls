/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: canastas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 16:35:48 by canastas     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 15:54:27 by canastas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include "libft/libft.h"
# include <errno.h>
# include <sys/ioctl.h>

typedef struct winsize	t_winsize;

typedef struct stat		t_stat;

typedef struct dirent	t_dir;

typedef struct			s_opt
{
	char				**argv_name;
	char				**argv_files;
	int					size_files;
	int					size_argv;
	DIR					*fd;
	int					space_link;
	int					space_size;
	int					space_uid;
	int					space_gid;
	struct group		*grp;
	struct passwd		*pwd;
	int					opt_a;
	int					opt_l;
	int					opt_r;
	int					opt_t;
	int					opt_r_up;
	int					opt_b;
	int					opt_o;
	int					opt_g;
}						t_opt;

typedef struct			s_list_ls
{
	char				*name;
	int					is_dir;
	struct s_list_ls	*next;
	time_t				modif_time;
}						t_list_ls;

void					read_dir(t_list_ls **s1, t_list_ls **names,
						t_opt opt, char *dirname);
void					actions_dir(t_list_ls *dir);
void					action_dir_pre(char *root, t_list_ls *s1,
						t_opt *options);
void					action_file(t_list_ls *file);
int						recursive_dir (char *dirname, t_opt options);
void					find_dir(t_list_ls *n, t_list_ls **s1,
						t_list_ls **names);
t_list_ls				*put_in_list(char *filename, char **new_root,
						t_opt options);
void					display_list(t_list_ls *file_list, t_opt options,
						char *filename);
t_list_ls				*sorted_lists(t_list_ls *first, t_list_ls *second,
						int(*compare)(t_list_ls *first, t_list_ls *second));
void					front_back_split(t_list_ls *source, t_list_ls **front,
						t_list_ls **back);
void					merge_sort(t_list_ls **list, t_opt options);
int						compare_time(t_list_ls *first, t_list_ls *second);
int						compare_time_reverse(t_list_ls *first,
						t_list_ls *second);
int						compare_alphabetic(t_list_ls *first,
						t_list_ls *second);
int						compare_alphabetic_reverse(t_list_ls *first,
						t_list_ls *second);
void					file_permissions(t_stat file_stat);
void					file_info(char *file_name, char *directory,
						t_opt options);
void					file_g_u_id(t_stat file_stat, t_opt options);
void					max_nr(char *root, t_list_ls *s1, t_opt *options);
void					print_int(long size, int space);
void					print_string(char *str, int space);
void					max_gid_uid(char *root, t_list_ls *s1, t_opt *options);
void					display_color(char *directory);
void					ft_putnbr_long(long n);
void					display_year(t_stat file_stat);
void					list_alloc(t_list_ls **n, t_dir *f, t_stat st,
						char *new_dir);
void					display_color(char *directory);
void					time_info(t_stat file_stat);
int						count_file(int argc, char **argv);
int						count_dir(int argc, char **argv);
char					**argv_file(int argc, char **argv, int size);
char					**argv_folder(int argc, char **argv, int size);
char					**sort_argv(char **str, int size);
void					check_opt(int *i, char **argv);
int						options(t_opt *option, char **arg);
void					error_opt(char **argv);
void					function_total(char *root, t_list_ls *s1, t_opt opt);
void					permission_error(char *dirname);
int						check_same_name(char *root, t_opt options);
int						verif_opt(char *arg, char comp_char);
int						list_size(t_list_ls *s1);

#endif
