#include "ft_ls.h"

void get_time(s_list * list)
{
    s_list * tmp = list;
    time_t tm = list->modif_time;
    s_stat buf;
    while(tmp != NULL)
    {

        printf("%s- %s\n",tmp->name,ctime(&tm));

        if (tmp->next == NULL)
            break;
        tmp = tmp->next;

        if(tmp->modif_time > tm)
        {
            printf("ceao");
        }
        tm=tmp->modif_time;
    }
}
s_list *put_in_list(char * filename, char **new_root, s_opt options)
{
    s_list *tmp_list;
   // DIR * FD;
    s_stat st;
    s_list *second_tmp = NULL;
    if (NULL == (*new_root = malloc((ft_strlen(filename) + 2))))
        exit(EXIT_FAILURE);
    memcpy(*new_root,filename,ft_strlen(filename));
    if ((*new_root)[ft_strlen(filename) - 1] != '/')
        (*new_root)[ft_strlen(filename)] = '/';
    (*new_root)[ft_strlen(filename) + 1] = '\0';
    if(NULL == (options.fd = opendir(*new_root)))
    {
        lstat(filename,&st);
        if (S_ISREG(st.st_mode) || S_ISCHR(st.st_mode) || S_ISFIFO(st.st_mode) || S_ISBLK(st.st_mode) ||
            S_ISLNK(st.st_mode) || S_ISSOCK(st.st_mode))
        {
            if (NULL == (second_tmp = malloc((sizeof *second_tmp))))
                exit(EXIT_FAILURE);
            second_tmp->name=filename;
            (options.opt_l==1 ? file_info(second_tmp->name,filename) : action_file(second_tmp));
            free(second_tmp);
            exit(0);
        }
        else
        {
            printf("open dir error\n");
            exit(1);
        }
    }
    tmp_list = second_tmp;
    read_dir(&tmp_list,&second_tmp,options,*new_root);
    tmp_list = second_tmp;
    return tmp_list;
}

void display_list(s_list *s1, s_opt options, char * filename)
{
    char *new_name;
    while (s1)
    {
        if (options.opt_l == 1) {
            new_name = ft_strjoin(filename, s1->name);
            file_info(s1->name,new_name);
            free(new_name);
        }
        else {

                actions_dir(s1);

        }
        s1 = s1->next;
    }
    ft_putchar('\n');
}