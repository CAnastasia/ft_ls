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
#include <time.h>
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
  time_t modif_time;

}              s_list;

void read_dir(s_list **s1, s_list **names, DIR * FD, char * dirname);
void actions_dir (s_list  *dir);
void action_dir_pre(const char *root, const char *dir);
void action_file(s_list  *file);
int recursive_dir (char *dirname);
void find_dir(s_list *n, s_list **s1, s_list **names);
void get_time(s_list * list);
s_list *put_in_list(char *filename, char ** new_root);
void display_list(s_list *file_list);
s_list *sorted_lists(s_list *first, s_list * second);
void front_back_split(s_list *source, s_list **front,s_list **back);
void merge_sort(s_list **list);

#endif
