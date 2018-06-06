/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:54:41 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/06 21:46:07 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

static void 	find_max_len_usr(struct stat f_stat, t_opt *options)
{
	struct passwd	*usr_pwd;

	usr_pwd = getpwuid(f_stat.st_uid);
    if (usr_pwd && ft_strlen(usr_pwd->pw_name) > options->len_usr)
    	options->len_usr = ft_strlen(usr_pwd->pw_name);
    else if (!(usr_pwd) && ft_strlen(ft_itoa((int)f_stat.st_uid)) > options->len_usr)
    	options->len_usr = ft_strlen(ft_itoa((int)f_stat.st_uid));	
}

static void		find_max_len_grp(struct stat f_stat, t_opt *options)
{
	struct group		*grp_pwd;

	grp_pwd = getgrgid(f_stat.st_gid);
    if (grp_pwd && ft_strlen(grp_pwd->gr_name) > options->len_grp)
    	options->len_grp = ft_strlen(grp_pwd->gr_name);
    else if (!(grp_pwd) && ft_strlen(ft_itoa((int)f_stat.st_gid)) > options->len_grp)
    	options->len_grp = ft_strlen(ft_itoa((int)f_stat.st_gid));	
}

static void		find_max_lnk_n_size(struct stat f_stat, t_opt *options)
{

	if (f_stat.st_nlink > options->max_lnk)
		options->max_lnk = f_stat.st_nlink;
	if (f_stat.st_size > options->max_size)
    	options->max_size = f_stat.st_size;
}

int    			find_max_for_each(t_file *lst, t_opt *options)
{
    struct stat     f_stat;
    t_file          *tmp;
    int             i;

    i = 0;
    tmp = lst;
    while (lst)
    {
        i++;
        if (lstat(lst->path, &f_stat) == 0)
            options->d_size += f_stat.st_blocks;
        find_max_lnk_n_size(f_stat, options);
	    find_max_len_usr(f_stat, options);
	    find_max_len_grp(f_stat, options);
        lst = lst->next;
    }
    lst = tmp;
    if (i == 2 && options->a != 1)
        return (-1);
    return (1);
}