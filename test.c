#include <sys/types.h>
#include <dirent.h>
#include "libft/libft.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *sd;
	dir = opendir(argv[1]);
	if (dir == NULL)
	{
		return (1);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.')
		{
			ft_putstr(sd->d_name);
			ft_putchar('\n');
		}
	}
	closedir(dir);
	return (0);
}
