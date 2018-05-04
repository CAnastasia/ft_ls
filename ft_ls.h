#ifndef FT_LS
# define FT_LS
#include <sys/stat.h>

/*typedef struct s_data
{
  char name[1024];
  struct stat info;
  struct passwd pwd;

}              t_data;
typedef struct s_node
{
  t_data data;
  struct s_node *left;
  struct s_node *right;
}             t_node;

*/
typedef struct slist_t
{
  char *name;
  int is_dir;
  struct slist_t *next;

}              s_list;
#endif
