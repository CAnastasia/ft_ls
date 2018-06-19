#include "ft_ls.h"

s_list *sorted_lists(s_list *first, s_list *second, int(*compare)(s_list * first, s_list *second))
{
    s_list *res = NULL;

    if(first == NULL)
        return (second);
    else if (second == NULL)
        return (first);
    if (compare(first,second))
    {
        res = first;
        res->next = sorted_lists(first->next, second,compare);
    }
    else
    {
        res = second;
        res->next = sorted_lists(first, second->next,compare);
    }
    return (res);
}
void front_back_split(s_list *source, s_list **front,s_list **back)
{
    s_list *fast;
    s_list *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}
void merge_sort(s_list **list, s_opt options)
{
    s_list *tmp;
    s_list *first;
    s_list *second;
    tmp = *list;

    if ((tmp == NULL) || (tmp->next == NULL))
        return;
    front_back_split(tmp, &first, &second);
    merge_sort(&first, options);
    merge_sort(&second, options);

    if (options.opt_t && !options.opt_r)
        *list = sorted_lists(first, second,compare_time);
    else if (options.opt_t && options.opt_r)
        *list = sorted_lists(first, second, compare_time_reverse);
    else if (options.opt_r)
        *list = sorted_lists(first, second,compare_alphabetic_reverse);
    else
        *list = sorted_lists(first, second,compare_alphabetic);
}