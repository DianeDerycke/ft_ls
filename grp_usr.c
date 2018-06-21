/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_usr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:14:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/22 00:18:45 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	field_user(struct stat f_stat, t_opt *options)
{
	struct passwd   *usr_pwd;
	char			*tmp;

	usr_pwd = getpwuid(f_stat.st_uid);
	tmp = NULL;
	if (usr_pwd)
        display_usr_grp(options->len_usr, usr_pwd->pw_name);
	else if (f_stat.st_uid)
        display_number(options->len_usr, ft_itoa(f_stat.st_uid));
    ft_putchar(' ');
}

void	field_grp(struct stat f_stat, t_opt *options)
{
    struct group   *grp_pwd;
    char			*tmp;

    tmp = NULL;
    grp_pwd = getgrgid(f_stat.st_gid);
    if (grp_pwd && (S_ISCHR(f_stat.st_mode) || S_ISBLK(f_stat.st_mode)))
    {
        ft_putstr(grp_pwd->gr_name);
        ft_putstr(" ");
        ft_putnbr((int)major(f_stat.st_rdev));
        ft_putstr(", ");
        ft_putnbr((int)minor(f_stat.st_rdev));
        ft_putchar(' ');
    }
    else if (grp_pwd)
        display_usr_grp(options->len_grp, grp_pwd->gr_name);
	else if (f_stat.st_gid)
        display_number(options->len_grp, ft_itoa(f_stat.st_gid));
}