#include "ft_ls.h"

int open_dir_list(s_list **second_tmp, char* filename, char** new_root, s_opt * options)
{
    s_stat st;

    if(NULL == (options->fd = opendir(*new_root)))
    {
        if(lstat(filename,&st) < 0)
        {
            write(1, "ft_ls: '", 9);
            write(1, *new_root, ft_strlen(*new_root));
            write(1, "': No such file or directory", 28);
            return(1);
        }
        if (S_ISREG(st.st_mode) || S_ISCHR(st.st_mode) || S_ISFIFO(st.st_mode) || S_ISBLK(st.st_mode) ||
            S_ISLNK(st.st_mode) || S_ISSOCK(st.st_mode))
        {
            if (NULL == (*second_tmp = malloc((sizeof **second_tmp))))
                exit(EXIT_FAILURE);
            (*second_tmp)->name = filename;
            (options->opt_l == 1 ? file_info((*second_tmp)->name,filename, *options) : action_file(*second_tmp));
            free(*second_tmp);
            *second_tmp=NULL;
            return(1);
        }
    }
    return(0);
}

s_list *put_in_list(char * filename, char **new_root, s_opt options)
{
    s_list *tmp_list;
    s_list *second_tmp;

    second_tmp = NULL;
    if (NULL == (*new_root = malloc((ft_strlen(filename) + 2))))
        exit(EXIT_FAILURE);
    memcpy(*new_root,filename,ft_strlen(filename));
 //   if ((*new_root)[ft_strlen(filename) - 1] != '/')
   // {
        (*new_root)[ft_strlen(filename)] = '/';
        (*new_root)[ft_strlen(filename) + 1] = '\0';
    //}
    //else
      //  (*new_root)[ft_strlen(filename)] = '\0';
    if(open_dir_list(&second_tmp, filename, new_root, &options))
    {
        free(*new_root);
        return second_tmp;
    }
    tmp_list = second_tmp;
    read_dir(&tmp_list,&second_tmp,options,*new_root);
    tmp_list = second_tmp;
    return (tmp_list);
}

void display_list(s_list *s1, s_opt options, char * filename)
{
    char *new_name;
    while (s1)
    {
        if (options.opt_l == 1) {
            new_name = ft_strjoin(filename, s1->name);
            file_info(s1->name,new_name, options);
            free(new_name);
        }
        else
        {
            new_name = ft_strjoin(filename, s1->name);
            display_color(new_name);
            free(new_name);
            actions_dir(s1);
            if(s1->next==NULL)
                ft_putchar('\n');
            write(1,"\033[0m",4);
        }
        s1 = s1->next;
    }
}