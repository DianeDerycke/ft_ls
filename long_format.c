/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:08:24 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/21 01:41:55 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

char    ext_attr(char *path)
{
    if (listxattr(path, NULL, 1, XATTR_NOFOLLOW) > 0)
        return ('@');
    return (' ');

}

void    display_mod(struct stat f_stat, char *path)
{
    char      mod[13];

    if (S_ISBLK(f_stat.st_mode))
        mod[0] = 'b';
    else if (S_ISCHR(f_stat.st_mode))
        mod[0] = 'c';
    else if (S_ISDIR(f_stat.st_mode))
        mod[0] = 'd';
    else if (S_ISLNK(f_stat.st_mode))
        mod[0] = 'l';
    else if (S_ISSOCK(f_stat.st_mode))
        mod[0] = 's';
    else if (S_ISFIFO(f_stat.st_mode))
        mod[0] = 'p';
    else
        mod[0] = '-';
    mod[1] = (f_stat.st_mode & S_IRUSR) ? 'r' : '-';
    mod[2] = (f_stat.st_mode & S_IWUSR) ? 'w' : '-';
    if (f_stat.st_mode & S_ISUID)
        mod[3] = f_stat.st_mode & S_IXUSR ? 's' : 'S';
    else
        mod[3] = (f_stat.st_mode & S_IXUSR) ? 'x' : '-';//
    mod[4] = (f_stat.st_mode & S_IRGRP) ? 'r' : '-';
    mod[5] = (f_stat.st_mode & S_IWGRP) ? 'w' : '-';
    if (f_stat.st_mode & S_ISGID)
        mod[6] = f_stat.st_mode & S_IXGRP ? 's' : 'S';
    else
        mod[6] = (f_stat.st_mode & S_IXGRP) ? 'x' : '-';//
    mod[7] = (f_stat.st_mode & S_IROTH) ? 'r' : '-';
    mod[8] = (f_stat.st_mode & S_IWOTH) ? 'w' : '-';
    if (f_stat.st_mode & S_ISVTX)
        mod[9] = f_stat.st_mode & S_IXOTH ? 't' : 'T';
    else
        mod[9] = (f_stat.st_mode & S_IXOTH) ? 'x' : '-';//
    mod[10] = ext_attr(path);
    mod[11] = '\0';
    ft_putstr(mod);
}

void    display_info(struct stat f_stat, t_opt *options)
{
    char            *max;

    // Display total link
    max = ft_itoa(options->max_lnk);
    display_number(ft_strlen(max), ft_itoa(f_stat.st_nlink));
    if (max)
        ft_strdel(&max);
    field_user(f_stat, options);
    field_grp(f_stat, options);
    //Display size file
    max = ft_itoa(options->max_sizef);
    display_number(ft_strlen(max), ft_itoa(f_stat.st_size));
    if (max)
        ft_strdel(&max);
}

void    display_time(struct stat f_stat)
{
    char            *time_cat;
    time_t          curr_t;
    int             six_months;

    curr_t = time(&curr_t);
    six_months = 15778800;
    if ((f_stat.st_mtime < (curr_t - six_months)) || 
        (f_stat.st_mtime > curr_t + six_months))
        time_cat = concat_time_year(ctime(&f_stat.st_mtime));
    else
        time_cat = concat_time(ctime(&f_stat.st_mtime));
    ft_putstr(time_cat);
    ft_putchar(' ');
    ft_strdel(&time_cat);
}

int     long_format(char *path, char *filename, t_opt *options)
{
    struct stat     f_stat;
    char            *line;

    line = NULL;
    if (lstat(path,&f_stat) < 0)
        return (EXIT_FAILURE);
    display_mod(f_stat, path);
    display_info(f_stat, options);
    display_time(f_stat);
    if (S_ISLNK(f_stat.st_mode))
        display_link(path, filename);
    else
        ft_putendl(filename);
    return (EXIT_SUCCESS);
}