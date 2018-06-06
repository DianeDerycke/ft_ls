/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:08:24 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/06 22:21:07 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

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
    ft_putstr((f_stat.st_mode & S_IXOTH) ? "x" : "-");
    //if no attribute > go mettre un espace
    ft_putchar(' ');
}

void    dis_info(struct stat f_stat, t_opt *options)
{
    struct passwd   *usr_pwd;
    struct group   *grp_pwd;
    char            *tmp;

    usr_pwd = getpwuid(f_stat.st_uid);
    grp_pwd = getgrgid(f_stat.st_gid);

    tmp = create_field(ft_strlen(ft_itoa(options->max_lnk)), ft_itoa(f_stat.st_nlink));
    ft_putstr(tmp);
    ft_putchar(' ');
    free(tmp);
    if (usr_pwd)
    {
        tmp = create_field_usr_grp(options->len_usr, usr_pwd->pw_name);
        ft_putstr(tmp);
        free(tmp);
    }
    else if (f_stat.st_uid)
    {
        tmp = create_field(options->len_usr, ft_itoa(f_stat.st_uid));
        ft_putstr(tmp);
        free(tmp);
    }
    ft_putstr("  ");
    if (grp_pwd)
    {
        tmp = create_field_usr_grp(options->len_grp, grp_pwd->gr_name);
        ft_putstr(tmp);
        free(tmp);
    }
    else if (f_stat.st_gid)
    {
        tmp = create_field(options->len_grp, ft_itoa(f_stat.st_gid));
        ft_putstr(tmp);
        free(tmp);
    }
    ft_putchar(' ');
    tmp = create_field(ft_strlen(ft_itoa(options->max_size)),ft_itoa(f_stat.st_size));
    ft_putstr(tmp);
    free(tmp);
    ft_putchar(' ');
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
        ft_putchar(' ');
        free(time_cat);
    }
}

int     long_format(char *path, char *filename, t_opt *options)
{
    struct stat     f_stat;

    if (lstat(path,&f_stat) < 0)
        return (1);
    dis_mode(f_stat);
    dis_info(f_stat, options);
    dis_time(f_stat);
    if (S_ISLNK(f_stat.st_mode))
        dis_link(path, filename);
    else
        ft_putendl(filename);
    return (0);
}