#include "ft_ls.h"

void file_g_u_id(s_stat file_stat, s_opt options)
{
    if ((options.pwd = getpwuid(file_stat.st_uid)) == NULL)
        print_string(ft_itoa(file_stat.st_uid), options.space_gid);
    else
        print_string(options.pwd->pw_name, options.space_uid);
    ft_putchar(' ');
    if (options.opt_o == 0)
    {
      if ((options.grp = getgrgid(file_stat.st_gid)) == NULL)
          print_string(ft_itoa(file_stat.st_gid), options.space_gid);
      else
          print_string(options.grp->gr_name, options.space_gid);
      ft_putchar(' ');
    }
}

void display_file_name(char *filename, char *directory)
{
    s_stat file_stat;
    char buf[1024];
    ssize_t len;

    if(lstat(directory, &file_stat) < 0)
        return;
    display_color(directory);
    write(1, filename, ft_strlen(filename));
    write(1,"\033[0m",4);
    if(S_ISLNK(file_stat.st_mode))
    {
        ft_putstr(" -> ");
        if ((len = readlink(directory, buf, sizeof(buf) - 1)) != -1)
            buf[len] = '\0';
        write(1, buf, ft_strlen(buf));
    }
    ft_putchar('\n');
}

void major_minor(s_stat file_stat, s_opt options)
{
    int dev;

    if(file_stat.st_rdev && (S_ISBLK(file_stat.st_mode) ||  S_ISCHR(file_stat.st_mode)))
    {
        dev = file_stat.st_rdev >> 24;
        ft_putnbr((unsigned int)dev & (0b0000000011111111));
        ft_putstr(", ");
        ft_putnbr((unsigned int)file_stat.st_rdev & (0b0000000011111111));
    }
    else
        print_int(file_stat.st_size, options.space_size);
}

void file_info(char *file_name,char *directory, s_opt options)
{
    s_stat file_stat;
    if(lstat(directory, &file_stat) < 0)
        return;
    file_permissions(file_stat);
    ft_putchar(' ');
    print_int(file_stat.st_nlink, options.space_link);
    ft_putchar(' ');
    file_g_u_id(file_stat, options);
    major_minor(file_stat, options);
    ft_putchar(' ');
    time_info(file_stat);
    ft_putchar(' ');
    display_file_name(file_name, directory);
}
void file_permissions(s_stat file_stat)
{
    ft_putstr((S_ISDIR(file_stat.st_mode) ? "d" :
               S_ISSOCK(file_stat.st_mode) ? "s" :
               S_ISCHR(file_stat.st_mode) ? "c" :
               S_ISFIFO(file_stat.st_mode) ? "p" :
               S_ISBLK(file_stat.st_mode) ? "b" :
               S_ISLNK(file_stat.st_mode) ? "l" : "-" ));
    ft_putstr((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr((file_stat.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr((file_stat.st_mode & S_IXOTH) ? "x" : "-");
}
