#include "ft_ls.h"

void actions_dir (s_list *dir)
{
    char fin ='\n';
    write(0,dir->name,ft_strlen(dir->name));
    write(0,&fin,1);
}

void function_total(char *root, s_list * s1)
{
    s_stat st;
    unsigned int size = 0;
    char *new_root;
    char *root_copy;
    int i = ft_strlen(root);
    char *tempo;

    new_root = ft_strdup(root);
    root_copy = ft_strjoin(new_root, "/");
    ft_putstr("total ");
    while(s1)
    {
        tempo=ft_strjoin(root_copy,s1->name);
        stat(tempo,&st);
        free(tempo);
        size +=st.st_blocks/2;
        s1 = s1->next;
    }
    free(new_root);
    free(root_copy);
    ft_putnbr(size);
    ft_putchar('\n');

}

void action_dir_pre(char *root,s_list * s1)
{
    ft_putstr(root);
    ft_putchar(':');
    ft_putchar('\n');
    function_total(root,s1);
}
void action_file(s_list *file)
{
    char fin ='\n';
    write(0,file->name,ft_strlen(file->name));
    write(0,&fin,1);
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
    while ((f = readdir(options.fd)) != NULL) {
        s_list *n;
        char *new_dir;
        char *dir_2;
        new_dir=ft_strdup(dirname);
        dir_2 = new_dir;
       // if ((strcmp(f->d_name, ".")) && (strcmp(f->d_name, ".."))) {
        if (f->d_name[0] != '.') {

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

int recursive_dir (char *dirname, s_opt options)
{
    s_list *names = NULL;
    s_list *s1;
    s_list *tmp_list = NULL;
    char *new_root;
    names = put_in_list(dirname,&new_root,options);
    action_dir_pre(dirname,names);//am schimbat merge cu action dir

    merge_sort(&names);
   // s1 = names;
    s1=names;
    display_list(s1,options,new_root);
     while (s1)
     {
       char *tmp_dir;
       if(s1->is_dir)
       {
         char * dirtemp;
         dirtemp=strdup(new_root);
         tmp_dir = dirtemp;
         dirtemp=ft_strjoin(new_root,(char*)s1->name);
         free(tmp_dir);
         recursive_dir(dirtemp,options);
         free(dirtemp);
       }
       s1= s1->next;
     }
    free(new_root);
    while(names != NULL)
    {
        s_list *prev;
        free(names->name);
        prev = names;
        names = names->next;
        free(prev);
    }
    return 0;
}
