/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:08:24 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/03 22:04:11 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void    get_right_size(char *path, t_opt *options)
{
    struct stat     file_stat;
    DIR             *openf;
    struct dirent   *readf;
    char            *tmp;
    int             i;

    options->d_size = 0;
    i = 0;
    if (!(openf = opendir(path)))
        return ;
    while ((readf = readdir(openf)) != NULL)
    {
        i++;
        if (options->a != 1 && readf->d_name[0] == '.')
            continue ;
        tmp = create_path(path, readf->d_name);
        if (lstat(tmp, &file_stat) == 0)
            options->d_size += file_stat.st_blocks;
        free(tmp);
    }
    closedir(openf);
    if (i == 2 && options->a != 1)
        return ;
    ft_putstr("total ");
    ft_putnbr(options->d_size);
    ft_putchar('\n');
}

void    dis_mode(struct stat f_stat)
{
    if (S_ISBLK(f_stat.st_mode))
        ft_putstr("b");
    else if (S_ISCHR(f_stat.st_mode))
        ft_putstr("c");
    else if (S_ISDIR(f_stat.st_mode))
        ft_putstr("d");
    else if (S_ISLNK(f_stat.st_mode))
        ft_putstr("l");
    else if (S_ISSOCK(f_stat.st_mode))
        ft_putstr("s");
    else if (S_ISFIFO(f_stat.st_mode))
        ft_putstr("p");
    else
        ft_putstr("-");
    ft_putstr((f_stat.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr((f_stat.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr((f_stat.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr((f_stat.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((f_stat.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr((f_stat.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr((f_stat.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr((f_stat.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr((f_stat.st_mode & S_IXOTH) ? "x  " : "-  ");
}

void    dis_info(struct stat f_stat)
{
    struct passwd   *usr_pwd;
    struct group   *grp_pwd;
    
    usr_pwd = getpwuid(f_stat.st_uid);
    grp_pwd = getgrgid(f_stat.st_gid);
    
    ft_putnbr(f_stat.st_nlink);
    ft_putchar(' ');
    if (usr_pwd)
    {
        ft_putstr(usr_pwd->pw_name);
        ft_putstr("   ");
    }
    else
    {
        ft_putnbr_u(f_stat.st_uid);
        ft_putstr("   ");
    }
    if (grp_pwd)
    {
        ft_putstr(grp_pwd->gr_name);
        ft_putstr("   ");
    }
    else if (f_stat.st_gid)
    {
        ft_putnbr_u(f_stat.st_gid);
        ft_putstr("   ");
    }
    ft_putnbr_ld(f_stat.st_size);
    ft_putstr("   ");
}

void    dis_time(struct stat f_stat)
{
    char            *time_cat;
    time_t          curr_t;

    time_cat = NULL;
    curr_t = time(&curr_t);
    if ((f_stat.st_mtime < (curr_t - 15778800)) || (f_stat.st_mtime > curr_t + 15778800))
    {
        time_cat = concat_time_year(ctime(&f_stat.st_mtime));
        ft_putstr(time_cat);
        ft_putchar(' ');
        free(time_cat);
    }
    else
    {
        time_cat = concat_time(ctime(&f_stat.st_mtime));
        ft_putstr(time_cat);
        ft_putstr(" ");
        free(time_cat);
    }
}

int     long_format(char *path, char *filename)
{
    struct stat     f_stat;

    if (lstat(path,&f_stat) < 0)
        return (1);
    dis_mode(f_stat);
    dis_info(f_stat);
    dis_time(f_stat);
    if (S_ISLNK(f_stat.st_mode))
        dis_link(path, filename);
    else
        ft_putendl(filename);
    return (0);
}