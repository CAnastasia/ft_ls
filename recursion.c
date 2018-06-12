#include "ft_ls.h"

void actions_dir (s_list *dir)
{
    write(1, dir->name, ft_strlen(dir->name));
    write(1, "  ", 2);
}


void function_total(char *root, s_list * s1)
{
    s_stat st;
    unsigned int size = 0;
    char *new_root;
    char *root_copy;
    char *tempo;


    new_root = ft_strdup(root);
    root_copy = ft_strjoin(new_root, "/");
    ft_putstr("total ");
    while(s1 != NULL)
    {
        tempo = ft_strjoin(root_copy,s1->name);
        stat(tempo,&st);
        free(tempo);
        size += st.st_blocks/2;
        s1 = s1->next;
    }
    free(new_root);
    free(root_copy);
    ft_putnbr(size);
    ft_putchar('\n');
}

void print_int(int size, int space)
{
   int i;
   int size_str;
   char *str_itoa;

   i = 0;
   str_itoa = ft_itoa(size);
   size_str = ft_strlen(str_itoa);
   while (i < space-size_str)
   {
       ft_putchar(' ');
       i++;
   }
   ft_putnbr(size);
   free(str_itoa);
}

void print_string(char * str, int space)
{
    int i;
    int size_str;

    i = 0;
    size_str = ft_strlen(str);
    ft_putstr(str);
    while (i < space - size_str)
    {
        ft_putchar(' ');
        i++;
    }
}

void action_dir_pre(char *root,s_list * s1, s_opt * options)
{

    ft_putstr(root);
    ft_putchar(':');
    ft_putchar('\n');
    if (options->opt_l) {
        function_total(root, s1);
        max_nr(root, s1, options);
        max_gid_uid(root, s1, options);
    }
}

void action_file(s_list *file)
{
    display_color(file->name);
    write(1,file->name,ft_strlen(file->name));
    write(1,"\033[0m",4);
    write(1,"\n",1);
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

void read_dir(s_list **s1, s_list **names, s_opt options,char * dirname)
{
    s_stat st;
    d_dir *f;
    s_list *n;
    char *new_dir;
    char *dir_2;

    while ((f = readdir(options.fd)) != NULL) {
        new_dir=ft_strdup(dirname);
        dir_2 = new_dir;
        if (options.opt_a == 1 || f->d_name[0] != '.') {

            new_dir=ft_strjoin(new_dir,f->d_name);
            lstat(new_dir, &st);
            free(new_dir);
            list_alloc(&n,f , st);
            find_dir(n,s1,names);
        }
        free(dir_2);
    }
    closedir(options.fd);
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

    while (s1) {
        if (s1->is_dir) {
            dirtemp = strdup(new_root);
            tmp_dir = dirtemp;
            dirtemp = ft_strjoin(new_root, (char *) s1->name);
            free(tmp_dir);
            if (options.opt_R == 1) {
                if ((dirtemp[ft_strlen(dirtemp) - 2] != '.' && dirtemp[ft_strlen(dirtemp) - 1] != '.') ||
                    dirtemp[ft_strlen(dirtemp) - 1] != '.') {
                    ft_putchar('\n');
                    recursive_dir(dirtemp, options);
                }
            }
            free(dirtemp);
        }
        s1 = s1->next;
    }
}

int recursive_dir(char *dirname, s_opt options)
{
    s_list *names = NULL;
    s_list *s1;
    s_list *tmp_list = NULL;
    char *new_root;

    if((names = put_in_list(dirname,&new_root,options)) == NULL)
        return (1);
    merge_sort(&names, options);
    s1 = names;
    action_dir_pre(dirname,s1, &options);
    s1=names;
    display_list(s1,options,new_root);
    recursive_call(s1, new_root, options);
    free(new_root);
    while(names != NULL)
    {
        s_list *prev;
        free(names->name);
        prev = names;
        names = names->next;
        free(prev);
    }
    return (0);
}
