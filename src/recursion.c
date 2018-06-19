#include "ft_ls.h"

void read_dir(s_list **s1, s_list **names, s_opt options,char * dirname)
{
    s_stat st;
    d_dir *f;
    s_list *n;
    char *new_dir;
    char *dir_2;

    if (options.fd == NULL)
        permission_error(dirname);
    else
    {
        while ((f = readdir(options.fd)) != NULL && (new_dir = ft_strdup(dirname)))
        {
            dir_2 = new_dir;
            if (options.opt_a == 1 || f->d_name[0] != '.')
            {
                new_dir=ft_strjoin(new_dir,f->d_name);
                lstat(new_dir, &st);
                free(new_dir);
                list_alloc(&n, f ,st);
                find_dir(n, s1, names);
            }
            free(dir_2);
        }
        closedir(options.fd);
    }
}

void find_dir(s_list *n, s_list **s1, s_list **names)
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

void recursive_call(s_list *s1, char* new_root, s_opt options)
{
    char *tmp_dir;
    char *dirtemp;

    while (s1)
    {
        if (s1->is_dir)
        {
            dirtemp = strdup(new_root);
            tmp_dir = dirtemp;
            dirtemp = ft_strjoin(new_root, (char *) s1->name);
            free(tmp_dir);
            if (options.opt_R == 1)
            {
                if ((dirtemp[ft_strlen(dirtemp) - 2] != '.' && dirtemp[ft_strlen(dirtemp) - 1] != '.') ||
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

void free_list(s_list *names)
{
     while(names != NULL)
     {
         s_list *prev;
         free(names->name);
         prev = names;
         names = names->next;
         free(prev);
     }
}
int recursive_dir(char *dirname, s_opt options)
{
    s_list *names;
    s_list *s1;

    names = NULL;
    char *new_root;
    if(((names = put_in_list(dirname,&new_root,options)) == NULL) &&
    ((options.fd = opendir(dirname)) == NULL))
        return (1);
    if (options.fd != NULL)
        closedir(options.fd);
    merge_sort(&names, options);
    s1 = names;
    action_dir_pre(dirname,s1, &options);
    s1=names;
    display_list(s1,options,new_root);
    recursive_call(s1, new_root, options);
    free(new_root);
    free_list(names);
    return (0);
}
