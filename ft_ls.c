
#include "ft_ls.h"


int main(int argc, char **argv)
{
  char * test=argv[1];
  action_dir_pre(test,"");
  int n=recursive_dir(NULL, test);
  return (0);
}
