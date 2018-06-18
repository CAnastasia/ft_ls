
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
          write(1, "ft_ls: ", 7);
          write(1, arg[i], ft_strlen(arg[i]));
          write(1, ": ", 2);
          write(1,"No such file or directory ",26);
          write(1, "\n", 1);
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
int count_file(int argc, char **argv)
{
  int i;
  s_stat st;
  int count;

  i = 1;
  count = 0;
  while(i < argc)
  {
    if (lstat(argv[i], &st) == 0)
    {
        if(!S_ISDIR(st.st_mode))
        {
            count++;
        }
    }
    i++;
  }
    return (count);
}

int count_dir(int argc, char **argv)
{
  int i;
  s_stat st;
  int count;

  i = 1;
  count = 0;
  while(i < argc)
  {
    if (lstat(argv[i], &st) == 0)
    {
        if(S_ISDIR(st.st_mode))
        {
            count++;
        }
    }
    i++;
  }
   return (count);
}
char **argv_file(int argc, char **argv, int size)
{
    int i;
    int j;
    char **copy_argv;
     s_stat st;


    i = 1;
    j = 0;
    if (!(copy_argv = (char**)malloc(sizeof(*copy_argv) * size)))
        return (NULL);
    while(i < argc)
    {
        if (lstat(argv[i], &st) == 0)
        {
            if(!S_ISDIR(st.st_mode))
            {

                if (j < size)
                {
                    copy_argv[j] = ft_strdup(argv[i]);
                    j++;

                }
            }
        }
        i++;

    }
    return (copy_argv);
}
char **argv_folder(int argc, char **argv, int size)
{
    int i;
    int j;
    char **copy_argv;
     s_stat st;


    i = 1;
    j = 0;
    if (!(copy_argv = (char**)malloc(sizeof(*copy_argv) * size)))
        return (NULL);
    while(i < argc)
    {
        if(lstat(argv[i], &st) == 0)
        {
            if(S_ISDIR(st.st_mode))
            {
                if (j < size)
                {
                    copy_argv[j] = ft_strdup(argv[i]);
                    j++;

                }
            }
        }
        i++;

    }
    return (copy_argv);
}

char    **sort_argv(char **str, int size)
{
    char *temp;
    int  i;
    int j;
    char**argv_to_sort;

    argv_to_sort = str;
    i = 0;
    while(i < size)
    {
        j = i + 1;
        while(j < size)
        {
            if (ft_strcmp(argv_to_sort[i], argv_to_sort[j]) > 0)
            {

                temp = ft_strdup(argv_to_sort[i]);
                argv_to_sort[i] = ft_strdup(argv_to_sort[j]);
                argv_to_sort[j] = ft_strdup(temp);
                free(temp);
            }
            j++;
        }
        i++;
    }
    return(argv_to_sort);
}
int call_files(char**file_names, int size, s_opt opt)
{
    int i;
    int r;

    i = 0;
     while(i  <  opt.size_files)
     {
        r = recursive_dir(file_names[i],opt);
        if (i == size - 1)
            ft_putchar('\n');
        else if(opt.opt_l == 0)
            ft_putchar(' ');
        i++;
     }
}
void call_folders(char **folder_names, int size, s_opt opt)
{
    int i;
    int r;

    i = 0;
    while(i  <  size)
    {
        r = recursive_dir(folder_names[i],opt);
        if (i < size - 1)
            ft_putchar('\n');
        i++;
    }
}
void free_argv(char ***folder, char ***files, s_opt *opt)
{
int i = 0;
     if (opt->size_argv > 0)
     {
        while(i < opt->size_argv)
        {
            free(*folder[i]);
           // free(opt->argv_name[i]);
            i++;
        }

     }
     i =  0;
     if (opt->size_files > 0)
     {
        while(i < opt->size_files)
        {
           free(files[i]);
           //free(opt->argv_files[i]);
           i++;
        }
     }
}
int main(int argc, char **argv)
{
    int n;
    s_opt opt;
    char **folders;
    char **files;

    opt = (s_opt) {.opt_a = 0,.opt_l = 0, .opt_R = 0, .opt_r = 0, .opt_t = 0};
    error_opt(argv);
    options(&opt,argv);
    opt.size_argv = count_dir(argc,argv);
    opt.size_files = count_file(argc, argv);
    folders = argv_folder(argc, argv,  opt.size_argv);
    files = argv_file(argc, argv,  opt.size_files);
    opt.argv_name = sort_argv(folders,  opt.size_argv);
    opt.argv_files = sort_argv(files,  opt.size_files);
    if (opt.size_files == 0 && opt.size_argv == 0)
        n = recursive_dir(".", opt);
    call_files(opt.argv_files, opt.size_files, opt);
    if (opt.size_files > 0 && opt.size_argv > 0)
        ft_putchar('\n');
    call_folders(opt.argv_name,  opt.size_argv, opt);

    //free(files);
  //  ft_strdel(opt.argv_files);
  int i =0;
  if (opt.size_files > 0)
       {
          while(i < opt.size_files)
          {
             free(files[i]);
             i++;
          }
       }
    //free_argv(&folders, &files, &opt);

    return (0);
}
