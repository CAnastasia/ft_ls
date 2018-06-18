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
#include <pwd.h>
#include <grp.h>
#include "libft/libft.h"
#include <errno.h>


typedef struct stat s_stat;

typedef struct dirent d_dir;

typedef struct opt_t
{
    char **argv_name;
    char **argv_files;
    int size_files;
    int size_argv;
    DIR *fd;
    int space_link;
    int space_size;
    int space_uid;
    int space_gid;
    struct group *grp;
    struct passwd *pwd;
    int opt_a;
    int opt_l;
    int opt_r;
    int opt_t;
    int opt_R;

}              s_opt;

typedef struct slist_t
{
    char *name;
    int is_dir;
    struct slist_t *next;
    time_t modif_time;
}              s_list;

void read_dir(s_list **s1, s_list **names, s_opt options, char * dirname);
void actions_dir(s_list  *dir);
void action_dir_pre(char *root,s_list *s1, s_opt *options);
void action_file(s_list  *file, s_opt opt);
int recursive_dir (char *dirname, s_opt options);
void find_dir(s_list *n, s_list **s1, s_list **names);
void get_time(s_list * list);
s_list *put_in_list(char *filename, char ** new_root,s_opt options);
void display_list(s_list *file_list,s_opt options,char *filename);
s_list *sorted_lists(s_list *first, s_list *second, int(*compare)(s_list * first, s_list *second));
void front_back_split(s_list *source, s_list **front,s_list **back);
void merge_sort(s_list **list, s_opt options);
int compare_time(s_list *first, s_list * second);
int compare_time_reverse(s_list *first, s_list * second);
int compare_alphabetic(s_list *first, s_list * second);
int compare_alphabetic_reverse(s_list *first, s_list * second);
void file_permissions(s_stat file_stat);
void file_info(char *file_name, char *directory, s_opt options);
void file_g_u_id(s_stat file_stat, s_opt options);
void max_nr(char *root,s_list * s1, s_opt *options);
void print_int(long size, int space);
void print_string(char * str, int space);
void max_gid_uid(char *root, s_list * s1,s_opt *options);
void display_color(char* directory);
void	ft_putnbr_long(long n);

#endif
