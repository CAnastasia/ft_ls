#include "ft_ls.h"

void function_total(char *root, s_list * s1, s_opt opt)
{
    s_stat st;
    unsigned int size;
    char *new_root;
    char *root_copy;
    char *tempo;

    size = 0;
    new_root = ft_strdup(root);
    root_copy = ft_strjoin(new_root, "/");
    ft_putstr("total ");
    while(s1 != NULL)
    {
        tempo = ft_strjoin(root_copy,s1->name);
        stat(tempo,&st);
        free(tempo);
        if (opt.opt_b == 0)
          size += st.st_blocks;
        else
          size += st.st_blocks/2;
        s1 = s1->next;
    }
    free(new_root);
    free(root_copy);
    ft_putnbr(size);
    ft_putchar('\n');
}

void print_int(long size, int space)
{
   int i;
   int size_str;
   char *str_itoa;

   i = 0;
   str_itoa = ft_itoa(size);
   size_str = ft_strlen(str_itoa);
   while (i < space - size_str)
   {
       ft_putchar(' ');
       i++;
   }
    if (size == 2147483648)
    {
        ft_putnbr_long(size);
    }
    else
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

void permission_error(char *dirname)
{
    if (errno == EACCES)
    {
        write(1,"ft_ls: ", 7);
        write(1, dirname, ft_strlen(dirname));
        write(1, ": Permission denied\n", 20);
    }
    free(dirname);
}

int check_same_name(char *root , s_opt options)
{
    int i;
    int j;

    j = 0;
    i = 0;
    if (options.size_argv == 0)
    {
        if (ft_strcmp(".", root))
            j = 1;
    }
    while (i < options.size_argv)
    {
        if (ft_strcmp(options.argv_name[i], root))
            j = 1;
        i++;
    }
    return (j);
}
