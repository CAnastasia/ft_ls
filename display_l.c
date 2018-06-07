#include "ft_ls.h"

void file_g_u_id(s_stat file_stat)
{
    struct group *grp;
    struct passwd *pwd;

    pwd = getpwuid(file_stat.st_uid);
    ft_putstr(pwd->pw_name);
    ft_putchar(' ');
    grp = getgrgid(file_stat.st_gid);
    ft_putstr(grp->gr_name);
    ft_putchar(' ');
}
void display_file_name(char *filename, char *directory)
{
    s_stat file_stat;
    char buf[1024];
    ssize_t len;
    if(lstat(directory, &file_stat) < 0)
        return;
    ft_putstr(filename);
    if(S_ISLNK(file_stat.st_mode))
    {
        ft_putstr(" -> ");
        if ((len = readlink(directory, buf, sizeof(buf)-1)) != -1)
            buf[len] = '\0';
        ft_putstr(buf);
    }
    ft_putchar('\n');
}
void major_minor(s_stat file_stat)
{
    int dev;

    if(S_ISBLK(file_stat.st_mode) ||  S_ISCHR(file_stat.st_mode)) {
        dev= file_stat.st_rdev >> 8;
        ft_putnbr((unsigned int)dev & (0b0000000011111111));
        ft_putstr(", ");
        ft_putnbr((unsigned int)file_stat.st_rdev & (0b0000000011111111));
    }
    else
    {
        ft_putnbr(file_stat.st_size);
    }
}
void file_info(char *file_name,char *directory)
{
    s_stat file_stat;
    char tmp[9];

    if(lstat(directory, &file_stat) < 0)
        return;
    file_permissions(file_stat);
    ft_putchar(' ');
    ft_putnbr(file_stat.st_nlink);
    ft_putchar(' ');
    file_g_u_id(file_stat);
    major_minor(file_stat);
    ft_putchar(' ');
    ft_memcpy(tmp,ctime(&(file_stat.st_mtime))+4,4);
    tmp[4]='\0';
    ft_putstr(tmp);
    ft_putchar(' ');
    ft_putchar(' ');
    ft_memcpy(tmp,ctime(&(file_stat.st_mtime))+8,8);
    ft_putstr(tmp);
    ft_putchar(' ');
    display_file_name(file_name,directory);
}
void file_permissions(s_stat file_stat)
{
    ft_putstr((S_ISDIR(file_stat.st_mode) ? "d" :
               S_ISSOCK(file_stat.st_mode) ? "s" :
               S_ISCHR(file_stat.st_mode) ? "c" :
               S_ISFIFO(file_stat.st_mode) ? "p" :
               S_ISBLK(file_stat.st_mode) ? "b" :
               S_ISLNK(file_stat.st_mode) ? "l" : "-" ));
    ft_putstr( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr( (file_stat.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
}


