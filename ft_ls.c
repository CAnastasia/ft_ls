#include "ft_ls.h"
int verif_opt(char *arg,char comp_char)
{
    int ret;

    ret = 0;
    if(ft_strchr(arg, comp_char) != NULL)
        ret = 1;
    return (ret);
}
void options(s_opt *option,char ** arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (verif_opt(arg[i],'-'))
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
        }
        i++;
    }

}
int main(int argc, char **argv)
{
    int i;
    int k;
    int m;
    int n;

    i = 1;
    k = 0;
    m = 0;
    s_opt opt = {.opt_a = 0,.opt_l = 0, .opt_R = 0, .opt_r = 0, .opt_t = 0};

    options(&opt,argv);
    while (argv[i])
    {
        while(argv[i][k])
        {
            if (argv[i][k] == '-')
            {
                m++;
            }
            k++;
        }
        if(m>1)
        {
            write(1,"usage",5);
            exit(1);
        }
        m=0;
        if(verif_opt(argv[i],'-') == 0 || ft_strlen(argv[i]) == 1)
        {
            n = recursive_dir(argv[i],opt);
            if (i != argc - 1 || argc == 2)
                ft_putchar('\n');
        }
        i++;
    }
  return (0);
}
