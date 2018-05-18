#include "ft_ls.h"

void actions_dir (s_list *dir)
{
    char fin ='\n';
    char espace= ' ';
    write(0,dir->name,ft_strlen(dir->name));
    write(0,&espace,1);
    write(0,ctime(&(dir->modif_time)),ft_strlen(ctime(&(dir->modif_time))));
    write(0,&fin,1);
}
void action_dir_pre(const char *root, const char *dir)
{
    printf("%s%s:\n",root,dir);
}
void action_file(s_list *file)
{
    char fin ='\n';
    char espace= ' ';
    write(0,file->name,ft_strlen(file->name));
    write(0,&espace,1);
    write(0,ctime(&(file->modif_time)),ft_strlen(ctime(&(file->modif_time))));
    write(0,&fin,1);
}

void read_dir(s_list **s1, s_list **names, DIR * FD,char * dirname)
{
    s_stat st;
    d_dir *f;
    while ((f = readdir(FD)) != NULL) {
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
            if (NULL == (n = malloc((sizeof *n))))
                exit(EXIT_FAILURE);
            n->name = ft_strdup(f->d_name);
            n->modif_time=st.st_mtime;
            if (S_ISDIR(st.st_mode) && !(S_ISLNK(st.st_mode)))
                n->is_dir = 1;
            else
                n->is_dir = 0;
            n->next = NULL;
            find_dir(n,s1,names);
        }
        free(dir_2);
    }
    closedir(FD);
}

void find_dir(s_list *n, s_list **s1, s_list **names)
{
    if (*s1) {
        (*s1)->next = n;
        *s1 = n;
    }
    else {
        *names = n;
        *s1 = n;
    }
}

int recursive_dir (char *dirname)
{
    s_list *names = NULL;
    s_list *s1;
    s_list *tmp_list = NULL;
    char *new_root;

    names = put_in_list(dirname,&new_root);
  //  s1 = names;
   // tmp_list = s1;
    merge_sort(&names);
    //free(tmp_list);
    s1 = names;

    display_list(s1);
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
         action_dir_pre(new_root,s1->name);
         recursive_dir(dirtemp);
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
