/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:08:24 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/22 02:49:09 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void    display_link(char *path, char *filename)
{
    char    tmp[1024];
    int     buffsize;

    if ((buffsize = readlink(path, tmp, sizeof(tmp) - 1)) != -1)
        tmp[buffsize] = '\0';
    ft_putstr(filename ? filename : path);
    ft_putstr(" -> ");
    ft_putstr(tmp);
    ft_putchar('\n');
}

void    display_time(struct stat f_stat)
{
    time_t          curr_t;
    int             six_months;
    char            *time_cat;

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

void    display_info(struct stat f_stat, t_opt *options)
{
    char            *max;

    // Display number of links
    max = ft_itoa(options->max_lnk);
    display_number(ft_strlen(max), ft_itoa(f_stat.st_nlink));
    if (max)
        ft_strdel(&max);
    field_user(f_stat, options);
    field_grp(f_stat, options);
    //if special character file or block special file display major && minor
    // device number
    if ((S_ISCHR(f_stat.st_mode) || (S_ISBLK(f_stat.st_mode))))
        return (major_minor_dev_number(f_stat.st_rdev));
    //else display number bytes of the file
    max = ft_itoa(options->max_sizef);
    display_number(ft_strlen(max), ft_itoa(f_stat.st_size));
    ft_strdel(&max);
}

int     long_format(char *path, char *filename, t_opt *options)
{
    struct stat     f_stat;

    if (lstat(path,&f_stat) < 0)
        return (EXIT_FAILURE);
    file_type(f_stat.st_mode);
    permissions(f_stat.st_mode, path);
    display_info(f_stat, options);
    display_time(f_stat);
    if (S_ISLNK(f_stat.st_mode))
        display_link(path, filename);
    else
        ft_putendl(filename);
    return (EXIT_SUCCESS);
}