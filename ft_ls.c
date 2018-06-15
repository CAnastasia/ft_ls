
#include "ft_ls.h"

void	ft_putnbr_long(long n)
{
    long number;
    long digit;
    long new;

    number = (long)n;
    if (number < 0)
    {
        ft_putchar('-');
        number *= -1;
    }
    if (number >= 10)
    {
        digit = number / 10;
        ft_putnbr(digit);
    }
    new = number % 10;
    ft_putchar(new + 48);
}

int verif_opt(char *arg,char comp_char)
{
    int ret;

    ret = 0;
    if(ft_strchr(arg, comp_char) != NULL)
        ret = 1;
    return (ret);
}
void check_opt(int *i, char **argv)
{
    int j = 1;

    while(argv[*i][j])
    {
            if ((argv[*i][j] != 'l' && argv[*i][j] != 'R' && argv[*i][j] != 'r' &&
                 argv[*i][j] != 't' && argv[*i][j] != 'a'))
            {
                write(1, "./ft_ls: illegal option -- ", 27);
                write (1, &argv[*i][j], 1);
                write (1, "\n", 1);
                write(1, "usage: ./ft_ls [-Rrtarg] [file...]", 34);
                write (1, "\n", 1);
                exit(1);
            }

        j++;
    }
    j = 0;
}


void options(s_opt *option,char ** arg)
{
    int i;
    s_stat st;
    int opt = 0;

    i = 1;
    while (arg[i])
    {
        if(arg[i][0] != '-')
          break;
        if (verif_opt(arg[i],'-'))
        {
            check_opt(&i, arg);
            if (verif_opt(arg[i],'a'))
                option->opt_a = 1;
            if (verif_opt(arg[i],'l'))
                option->opt_l = 1;
            if (verif_opt(arg[i],'R'))
                option->opt_R = 1;
            if (verif_opt(arg[i],'r'))
                option->opt_r = 1;
            if (verif_opt(arg[i],'t'))
                option->opt_t = 1;
        }
        i++;
    }
    while(arg[i])
    {
       if(lstat(arg[i], &st) < 0)
       {
          write(1,"no such file or directory ",26);
          write(1, arg[i], ft_strlen(arg[i]));
        //  write(1, "\n", 1);
        }
       i++;
    }
}

void    error_opt(char **argv)
{
    int i;
    int j;
    int count;

    i = 1;
    j = 0;
    count = 0;
    while (argv[i])
    {
        while(argv[i][j])
        {
            if (argv[i][j] == '-' && argv[i - 1][j] == '-')
                count++;
            j++;
        }
        if(count > 1)
        {
            write(1, "usage: ./ft_ls [-Rrtarg] [file...]", 34);
            exit(1);
        }
        count = 0;
        j = 0;
        i++;
    }

}
int count_argv(char **argv)
{
  int i;
    int j;
  int count;

  i = 1;
  count = 0;
  while(argv[i])
  {

    if(argv[i][0] != '-')
    {
        count++;
    }
    i++;
  }
    return (count);
}
char **argv_string(int argc, char **argv)
{
    int i;
    int j;
    int size;
    char **copy_argv;

    i = 1;
    j = 0;
    size =  count_argv(argv);
    if (!(copy_argv = (char**)malloc(sizeof(*copy_argv) * size)))
        return (NULL);
    while(i < argc)
    {
        if(argv[i][0] != '-')
        {
            if (j < size)
            {
                copy_argv[j] = ft_strdup(argv[i]);
                j++;

            }
        }
        i++;

    }
    return (copy_argv);
}
char **sort_argv(int argc, char **argv, s_opt opt)
{
    char **argv_to_sort;
    char *temp;
    char **ret_str;
    int  i;
    int j;
    argv_to_sort = argv_string(argc, argv);
    i = 0;

    while(i < opt.size_argv)
    {
        j = i + 1;
        while(j < opt.size_argv)
        {
            if (strcmp(argv_to_sort[i], argv_to_sort[j]) > 0)
            {
                temp = ft_strdup(argv_to_sort[i]);
                argv_to_sort[i] = ft_strdup(argv_to_sort[j]);
                argv_to_sort[j] = ft_strdup(temp);
            }
            j++;
        }
        i++;
    }
    return argv_to_sort;
}

int main(int argc, char **argv)
{
    int i;
    int n;
    s_opt opt;
    char *argv_opt;
    int h =0;
    int p = 0;

    i = 0;
    opt = (s_opt) {.opt_a = 0,.opt_l = 0, .opt_R = 0, .opt_r = 0, .opt_t = 0};
    options(&opt,argv);
    error_opt(argv);
    p =  count_argv(argv);
    opt.size_argv = count_argv(argv);
    opt.argv_name = sort_argv(argc, argv, opt);
    while (i < argc)
    {

        i++;
        if (i == argc && h > 1)
          break;
        if((!argv[i] || verif_opt(argv[i],'-') == 0) && count_argv(argv) == 0)
        {
          argv_opt = ft_strdup(".");
          n = recursive_dir(argv_opt,opt);
          free(argv_opt);
        }
        else if(verif_opt(argv[i],'-') == 0 || ft_strlen(argv[i]) == 1)
        {
            printf("h: %d\n", h);
            n = recursive_dir(opt.argv_name[h],opt);
            h++;
            p--;
            if (p)
                ft_putchar('\n');
        }

    }
  return (0);
}
