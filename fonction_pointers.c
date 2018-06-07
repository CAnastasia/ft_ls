#include "ft_ls.h"
char * str_to_lower(char *str)
{
    char *new_str;
    int i = 0;
    new_str = ft_strnew(ft_strlen(str));

    while (i < ft_strlen(str))
    {
        new_str[i] = ft_tolower(str[i]);
        i++;
    }
    return (new_str);
}
int compare_time(s_list *first, s_list * second)
{
    int ret = 0;
    if (first->modif_time >= second->modif_time)
    {
        ret = 1;
    }
    return (ret);
}

int compare_time_reverse(s_list *first, s_list * second)
{
    int ret = 0;
    if (first->modif_time <= second->modif_time)
    {
        ret = 1;
    }
    return (ret);
}

int compare_alphabetic(s_list *first, s_list * second)
{
    int ret;
    char * first_name;
    char * second_name;

    first_name = str_to_lower(first->name);
    second_name = str_to_lower(second->name);

    ret = 0;
    if (ft_strcmp(first_name,second_name) < 0)
    {
        ret = 1;
    }
    ft_strdel(&first_name);
    ft_strdel(&second_name);
    return (ret);
}

int compare_alphabetic_reverse(s_list *first, s_list * second)
{
    int ret;
    char * first_name;
    char * second_name;

    first_name = str_to_lower(first->name);
    second_name = str_to_lower(second->name);
    ret = 0;
    if (ft_strcmp(first_name,second_name) > 0)
    {
        ret = 1;
    }
    ft_strdel(&first_name);
    ft_strdel(&second_name);
    return (ret);
}
