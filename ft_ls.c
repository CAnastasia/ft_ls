#include "ft_ls.h"

int main(int argc, char **argv)
{
  char * francais;
  char * test=argv[1];
  //action_dir_pre(test,"");

  int n=recursive_dir(test);
         //s_list *for_time = put_in_list(test,&francais);
          //display_list(for_time);
      //    get_time(for_time);
  return (0);
}
