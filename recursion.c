#include "ft_ls.h"

void actions_dir (const char *dir)
{
  printf("%s\n",dir);
}
void action_dir_pre(const char *root, const char *dir)
{
  printf("%s%s:\n",root,dir);
}
void action_file(const char *file)
{
  printf("%s\n",file );
}

void read_dir(s_list **s1, s_list **names, DIR * FD,char * dirname)
{
  s_stat st;
  d_dir *f;
  while ((f = readdir(FD)) != NULL) {
    s_list *n;
    char *new_dir;
    new_dir=strdup(dirname);
   if ((strcmp(f->d_name, ".")) && (strcmp(f->d_name, ".."))) {
      new_dir=ft_strjoin(new_dir,f->d_name);
      stat(new_dir, &st);
      if (NULL == (n = malloc((sizeof *n))))
        exit(EXIT_FAILURE);
      n->name = strdup(f->d_name);
      if (S_ISDIR(st.st_mode))
        n->is_dir = 1;
      else
        n->is_dir = 0;
      n->next = NULL;
      find_dir(n,s1,names);
      free(new_dir);
    }
  }
  closedir(FD);
}

void find_dir(s_list *n, s_list **s1, s_list **names)
{
  if (*s1) {
    (*s1)->next = n;
    *s1 = n;
  }
  else {
    *names = n;
    *s1 = n;
  }
}

int recursive_dir (char *root, char *dirname)
{
  s_list *names = NULL;
  s_list *s1;
  char *new_root;
  DIR *FD;
  int rootlen = 0;
  if(root != NULL)
    rootlen = strlen(root);
  int dirnamelen = strlen(dirname);
  if (NULL == (new_root = malloc((rootlen + dirnamelen + 2))))
      exit(EXIT_FAILURE);
  memcpy(new_root,dirname,rootlen + dirnamelen );
  new_root[dirnamelen] = '/';
  new_root[rootlen + dirnamelen + 1] = '\0';
  if(NULL == (FD = opendir(new_root)))
    return (-1);
  s1 = names;
  read_dir(&s1,&names,FD,new_root);
  s1 = names;
  while (s1)
  {
    if (s1->is_dir)
      actions_dir(s1->name);
    else
      action_file(s1->name);
    s1=s1->next;
  }
  s1 = names;
  while (s1)
  {
    if(s1->is_dir)
    {
      char * dirtemp;
      dirtemp=strdup(new_root);
      dirtemp=ft_strjoin(new_root,(char*)s1->name);
      action_dir_pre(new_root,s1->name);
      recursive_dir(new_root,dirtemp);
      free(dirtemp);
    }
    s1= s1->next;
  }
  free(new_root);
  while(names != NULL)
  {
    s_list *prev;
    free(names->name);
    prev = names;
    names = names->next;
    free(prev);
  }
  return 0;
}
