#include "ft_ls.h"

void check_opt(int *i, char **argv)
{
    int j;
    j = 1;

    while(argv[*i][j])
    {
        if ((argv[*i][j] != 'l' && argv[*i][j] != 'R' && argv[*i][j] != 'r' &&
            argv[*i][j] != 't' && argv[*i][j] != 'a' && argv[*i][j] != 'b' &&
            argv[*i][j] != 'o'))
        {
            write(1, "./ft_ls: illegal option -- ", 27);
            write (1, &argv[*i][j], 1);
            write (1, "\n", 1);
            write(1, "usage: ./ft_ls [-Rrtarob] [file...]", 34);
            write (1, "\n", 1);
            exit(1);
         }
        j++;
    }
    j = 0;
}
int no_directory(int i , char** arg)
{
  int ret;
  s_stat st;

  ret = 0;
  while(arg[i])
  {
     if(lstat(arg[i], &st) < 0)
     {
        ret = 1;
        write(1, "ft_ls: ", 7);
        write(1, arg[i], ft_strlen(arg[i]));
        write(1, ": ", 2);
        write(1,"No such file or directory ",26);
        write(1, "\n", 1);
      }
     i++;
  }
  return (ret);
}

void options_assignment(char **arg, int i, s_opt *option)
{
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
  if (verif_opt(arg[i],'b'))
      option->opt_b = 1;
  if (verif_opt(arg[i],'o'))
      option->opt_o = 1;
}
int options(s_opt *option,char ** arg)
{
    int i;
    int ret;

    i = 1;
    ret = 0;
    while (arg[i])
    {
        if(arg[i][0] != '-')
          break;
        if (verif_opt(arg[i],'-'))
        {
            check_opt(&i, arg);
            options_assignment(arg, i, option);
            ret = 2;
        }
        i++;
    }
    if (no_directory(i, arg))
      ret = 1;
return (ret);
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
            write(1, "usage: ./ft_ls [-Rrtarbo] [file...]", 34);
            exit(1);
        }
        count = 0;
        j = 0;
        i++;
    }
}
