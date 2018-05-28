/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:08:24 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/28 04:03:54 by DERYCKE          ###   ########.fr       */
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
    printf("total %d\n", options->d_size);
}

void    dis_mode(struct stat f_stat)
{
    if (S_ISBLK(f_stat.st_mode))
        printf("b");
    else if (S_ISCHR(f_stat.st_mode))
        printf("c");
    else if (S_ISDIR(f_stat.st_mode))
        printf("d");
    else if (S_ISLNK(f_stat.st_mode))
        printf("l");
    else if (S_ISSOCK(f_stat.st_mode))
        printf("s");
    else if (S_ISFIFO(f_stat.st_mode))
        printf("p");
    else
        printf("-");
    printf( (f_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (f_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (f_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (f_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (f_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (f_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (f_stat.st_mode & S_IROTH) ? "r" : "-");
    printf( (f_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (f_stat.st_mode & S_IXOTH) ? "x  " : "-  ");
}

void    dis_info(struct stat f_stat)
{
    struct passwd   *usr_pwd;
    struct group   *grp_pwd;
    
    usr_pwd = getpwuid(f_stat.st_uid);
    grp_pwd = getgrgid(f_stat.st_gid);
    
        printf("%d ",f_stat.st_nlink);
    if (usr_pwd)
        printf("%s   ", usr_pwd->pw_name);
    else
        printf("%u   ", f_stat.st_uid);
    if (grp_pwd)
        printf("%s   ", grp_pwd->gr_name);
    else if (f_stat.st_gid)
        printf("%u   ", f_stat.st_gid);
    printf("%lld   ",f_stat.st_size);
}

void    dis_time(struct stat f_stat)
{
    char            *time_cat;

    time_cat = concat_time(ctime(&f_stat.st_mtime));
    if (time_cat)
    {
        printf("%s ", time_cat);
        free(time_cat);
    }//if time > / < 6 months display year instead of time hours + min
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
        printf("%s\n", filename);
    return (0);
}