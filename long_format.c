/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:08:24 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/17 19:44:56 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

char    ext_attr(struct stat f_stat, char *path)
{
    char    buffer[101];

    (void)f_stat;
    if (listxattr(path, buffer, sizeof(buffer), XATTR_NOFOLLOW) > 0)
        return ('@');
    return (' ');

}

void    display_mode(struct stat f_stat, char *path)
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
    mod[3] = (f_stat.st_mode & S_IXUSR) ? 'x' : '-';//
    mod[4] = (f_stat.st_mode & S_IRGRP) ? 'r' : '-';
    mod[5] = (f_stat.st_mode & S_IWGRP) ? 'w' : '-';
    mod[6] = (f_stat.st_mode & S_IXGRP) ? 'x' : '-';//
    mod[7] = (f_stat.st_mode & S_IROTH) ? 'r' : '-';
    mod[8] = (f_stat.st_mode & S_IWOTH) ? 'w' : '-';
    mod[9] = (f_stat.st_mode & S_IXOTH) ? 'x' : '-';//
    mod[10] = ext_attr(f_stat, path);
    mod[11] = '\0';
    ft_putstr(mod);
}

void    display_info(struct stat f_stat, t_opt *options)
{
    char            *max;
    char            *tmp;

    max = ft_itoa(options->max_lnk);
    tmp = ft_itoa(f_stat.st_nlink);
    display_number(ft_strlen(max), tmp);
    free(max);
    free(tmp);

    field_user(f_stat, options);
    field_grp(f_stat, options);

    max = ft_itoa(options->max_size);
    tmp = ft_itoa(f_stat.st_size);
    display_number(ft_strlen(max), tmp);
    free(max);
    free(tmp);
}

void    display_time(struct stat f_stat)
{
    char            *time_cat;
    time_t          curr_t;

    time_cat = NULL;
    curr_t = time(&curr_t);
    if ((f_stat.st_mtime < (curr_t - 15778800)) || 
        (f_stat.st_mtime > curr_t + 15778800))
        time_cat = concat_time_year(ctime(&f_stat.st_mtime));
    else
        time_cat = concat_time(ctime(&f_stat.st_mtime));
    ft_putstr(time_cat);
    ft_putchar(' ');
    free(time_cat);
}

int     long_format(char *path, char *filename, t_opt *options)
{
    struct stat     f_stat;
    if (lstat(path,&f_stat) < 0)
        return (1);
    display_mode(f_stat, path);
    display_info(f_stat, options);
    display_time(f_stat);
    if (S_ISLNK(f_stat.st_mode))
        display_link(path, filename);
    else
        ft_putendl(filename);
    return (0);
}