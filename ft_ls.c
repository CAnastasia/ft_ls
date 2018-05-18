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
    int i = 0;
    char begin_opt = '-';
    while (arg[i])
    {
        if (verif_opt(arg[i],'-'))
        {
            if (verif_opt(arg[i],'a'))
                option->opt_a = 1;
            else
                option->opt_a = 0;
            printf("%d", option->opt_a);
        }
        i++;
    }

}
int main(int argc, char **argv)
{
  char * francais;
    int i = 1;
    s_opt opt = {.opt_a = 0,.opt_l = 0, .opt_R = 0, .opt_r = 0, .opt_t = 0};
    options(&opt,argv);
 // char * test=argv[2];
    while (argv[i])
    {
        if(verif_opt(argv[i],'-') == 0)
        {
            int n = recursive_dir(argv[i]);
        }
        else{
            printf("i'm here ");
        }
        i++;
    }
  //action_dir_pre(test,"");

         //s_list *for_time = put_in_list(test,&francais);
          //display_list(for_time);
      //    get_time(for_time);
  return (0);
}
