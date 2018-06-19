#include "ft_ls.h"

void display_year(s_stat file_stat)
{
    char tmp[5];

    ft_memcpy(tmp,ctime(&(file_stat.st_mtime)) + 4,4);
    tmp[4]='\0';
    ft_putstr(tmp);
    ft_putchar(' ');
    ft_putchar(' ');
    ft_memcpy(tmp,ctime(&(file_stat.st_mtime)) + 8, 3);
    tmp[3] = '\0';
    ft_putstr(tmp);
    ft_memcpy(tmp,ctime(&(file_stat.st_mtime)) + 20, 4);
    tmp[4] = '\0';
    ft_putstr(tmp);
}
void time_info(s_stat file_stat)
{
    char tmp[9];
    time_t seconds;

    seconds = time(NULL);
    if ((seconds - 15778463) < file_stat.st_mtime || seconds < file_stat.st_mtime)
    {
        ft_memcpy(tmp,ctime(&(file_stat.st_mtime)) + 4,4);
        tmp[4]='\0';
        ft_putstr(tmp);
        ft_putchar(' ');
        ft_putchar(' ');
        ft_memcpy(tmp,ctime(&(file_stat.st_mtime)) + 8, 8);
        tmp[8]='\0';
        ft_putstr(tmp);
    }
    else
    {
       display_year(file_stat);
    }
}
