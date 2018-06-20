/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:54:41 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/21 01:09:22 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

static void     find_max_len_usr(struct stat f_stat, t_opt *options)
{
    struct passwd   *usr_pwd;
    char            *uid;
    size_t          size_uid;

    usr_pwd = getpwuid(f_stat.st_uid);
    uid = ft_itoa(f_stat.st_uid);
    size_uid = ft_strlen(uid);
    ft_strdel(&uid);
    if (usr_pwd && ft_strlen(usr_pwd->pw_name) > options->len_usr)
        options->len_usr = ft_strlen(usr_pwd->pw_name);
    else if (!(usr_pwd) && size_uid > options->len_usr)
        options->len_usr = size_uid;    
}

static void     find_max_len_grp(struct stat f_stat, t_opt *options)
{
    struct group        *grp_pwd;
    char                *gid;
    size_t              size_gid;

    grp_pwd = getgrgid(f_stat.st_gid);
    gid = ft_itoa(f_stat.st_gid);
    size_gid = ft_strlen(gid);
    ft_strdel(&gid);
    if (grp_pwd && ft_strlen(grp_pwd->gr_name) > options->len_grp)
        options->len_grp = ft_strlen(grp_pwd->gr_name);
    else if (!(grp_pwd) && size_gid > options->len_grp)
        options->len_grp = size_gid;
}

static void     find_max_lnk_n_size(struct stat f_stat, t_opt *options)
{

    if (f_stat.st_nlink > options->max_lnk)
        options->max_lnk = f_stat.st_nlink;
    if (f_stat.st_size > options->max_sizef)
        options->max_sizef = f_stat.st_size;
}

int    			find_max_for_each(t_file *lst, t_opt *options)
{
    struct stat     f_stat;

    while (lst->next)
    {
        if (lstat(lst->path, &f_stat) == 0)
        {
            options->d_size += f_stat.st_blocks;
            find_max_lnk_n_size(f_stat, options);
    	    find_max_len_usr(f_stat, options);
    	    find_max_len_grp(f_stat, options);            
        }
        lst = lst->next;
    }
    return (EXIT_SUCCESS);
}