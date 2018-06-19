#include "ft_ls.h"

void actions_dir(s_list *dir)
{
    write(1, dir->name, ft_strlen(dir->name));
    write(1, "  ", 2);
}

void action_dir_pre(char *root,s_list * s1, s_opt * options)
{
    if (check_same_name(root, *options) || options->size_files > 0)
    {
        ft_putstr(root);
        ft_putchar(':');
        ft_putchar('\n');
    }
    if (options->opt_l) {
        if (s1 != NULL)
          function_total(root, s1, *options);
        max_nr(root, s1, options);
        max_gid_uid(root, s1, options);
    }
}

void action_file(s_list *file)
{
    display_color(file->name);
    write(1,file->name,ft_strlen(file->name));
    write(1,"\033[0m",4);
}

void display_color(char* directory)
{
    s_stat file_stat;

    if(lstat(directory, &file_stat) < 0)
        return;
    if(S_ISLNK(file_stat.st_mode))
        write(1,"\033[1;34m",7);
    if(S_ISFIFO(file_stat.st_mode))
        write(1,"\033[0;33m",7);
    if(S_ISBLK(file_stat.st_mode))
        write(1,"\033[0;32m",7);
    if(S_ISCHR(file_stat.st_mode))
        write(1,"\033[0;31m",7);
    if(S_ISSOCK(file_stat.st_mode))
        write(1,"\033[0;35m",7);
    if(S_ISDIR(file_stat.st_mode))
        write(1,"\033[0;36m",7);
}

void list_alloc(s_list **n, d_dir *f, s_stat st)
{
    if (NULL == ((*n) = malloc((sizeof **n))))
        exit(EXIT_FAILURE);
    (*n)->name = ft_strdup(f->d_name);
    (*n)->modif_time=st.st_mtime;
    if (S_ISDIR(st.st_mode) && !(S_ISLNK(st.st_mode)))
        (*n)->is_dir = 1;
    else
        (*n)->is_dir = 0;
    (*n)->next = NULL;
}
