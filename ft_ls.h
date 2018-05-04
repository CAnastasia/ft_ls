#ifndef FT_LS
# define FT_LS
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include "libft/libft.h"


/*typedef struct s_data
{


  //struct passwd pwd;


}              t_data;*/
typedef struct stat s_stat;

typedef struct dirent d_dir;

typedef struct slist_t
{
  char *name;
  int is_dir;
  struct slist_t *next;

}              s_list;

void read_dir(s_list **s1, s_list **names, DIR * FD, char * dirname);
void actions_dir (const char *dir);
void action_dir_pre(const char *root, const char *dir);
void action_file(const char *file);
int recursive_dir (char *root, char *dirname);
void find_dir(s_list *n, s_list **s1, s_list **names);
#endif
