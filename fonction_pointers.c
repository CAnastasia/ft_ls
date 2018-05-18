#include "ft_ls.h"

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
    int ret = 0;
    if (ft_strcmp(first->name,second->name) < 0)
    {
        ret = 1;
    }
    return (ret);
}

int compare_alphabetic_reverse(s_list *first, s_list * second)
{
    int ret = 0;
    if (ft_strcmp(first->name,second->name) > 0)
    {
        ret = 1;
    }
    return (ret);
}
