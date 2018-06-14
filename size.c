#include "ft_ls.h"


int list_size(s_list * s1)
{
    int size = 0;

    while(s1 != NULL)
    {
        size++;
        s1 = s1->next;
    }
    return (size);
}

void link_size(char *root, s_list * s1, int tab_size[list_size(s1)], int tab_link[list_size(s1)])
{
    s_stat st;
    char *new_root;
    char *root_copy;
    char * tempo;
    int i;


    i = -1;
    new_root = ft_strdup(root);
    root_copy = ft_strjoin(new_root, "/");
    while(s1 != NULL)
    {
        tempo = ft_strjoin(root_copy, s1->name);
        if(lstat(tempo, &st) < 0)
            return ;
        free(tempo);
        tempo = ft_itoa(st.st_size);
        tab_size[++i] = ft_strlen(tempo);
        free(tempo);
        tempo = ft_itoa(st.st_nlink);
        tab_link[i] = ft_strlen(tempo);
        free(tempo);
        s1 = s1->next;
    }
    free(new_root);
    free(root_copy);
}

void uid_size(char *root, s_list * s1, int tab_uid[list_size(s1)], s_opt *options)
{
    s_stat st;
    char *new_root;
    char *root_copy;
    char * tempo;
    int i;

    i = -1;
    new_root = ft_strdup(root);
    root_copy = ft_strjoin(new_root, "/");
    while(s1 != NULL)
    {
        tempo = ft_strjoin(root_copy, s1->name);
        if(lstat(tempo, &st) < 0)
            return ;
        free(tempo);
        if (((options)->pwd = getpwuid(st.st_uid)) == NULL)
            tempo = ft_itoa(st.st_uid);
        else
            tempo = (options)->pwd->pw_name;
        tab_uid[++i] = ft_strlen(tempo);
        s1 = s1->next;
    }
    free(new_root);
    free(root_copy);
}

void gid_size(char *root, s_list * s1, int tab_gid[list_size(s1)], s_opt *options)
{
    s_stat st;
    char *new_root;
    char *root_copy;
    char * tempo;
    int i;

    i = -1;
    new_root = ft_strdup(root);
    root_copy = ft_strjoin(new_root, "/");
   if(((options)->grp = getgrgid(st.st_gid)) == NULL)
        return;
    while(s1 != NULL)
    {
        tempo = ft_strjoin(root_copy, s1->name);
        if(lstat(tempo, &st) < 0)
            return ;
        free(tempo);
        if(((options)->grp = getgrgid(st.st_gid)) == NULL)
            tempo = ft_itoa(st.st_gid);
        else
            tempo = (options)->grp->gr_name;
        tab_gid[++i] = ft_strlen(tempo);
        s1 = s1->next;
    }
    free(new_root);
    free(root_copy);
}

void max_gid_uid(char *root, s_list * s1,s_opt *options)
{
    int i;
    int tab_uid[list_size(s1)];
    int tab_gid[list_size(s1)];
    int max_uid;
    int max_gid;

    i = 1;
    if (list_size(s1) > 0) {
        uid_size(root, s1, tab_uid, options);
        gid_size(root, s1, tab_gid, options);
        max_uid = tab_uid[0];
        max_gid = tab_gid[0];
        while (i < list_size(s1) - 1) {
            if (tab_uid[i] > max_uid)
                max_uid = tab_uid[i];
            if (tab_gid[i] > max_gid)
                max_gid = tab_gid[i];
            i++;
        }
        options->space_uid = max_uid;
        options->space_gid = max_gid;
    }
}
void max_nr(char *root, s_list * s1, s_opt *options)
{
    int i;
    int tab_size[list_size(s1)];
    int tab_link[list_size(s1)];
    int max_size;
    int max_link;

    i = 1;
    if (list_size(s1) > 0) {
        link_size(root, s1, tab_size, tab_link);
        max_size = tab_size[0];
        max_link = tab_link[0];
        while (i < list_size(s1) - 1) {
            if (tab_size[i] > max_size)
                max_size = tab_size[i];
            if (tab_link[i] > max_link)
                max_link = tab_link[i];
            i++;
        }
        options->space_size = max_size;
        options->space_link = max_link;
    }

}
