/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_usr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:14:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/22 01:58:33 by DERYCKE          ###   ########.fr       */
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
    if (grp_pwd->gr_name)
        display_usr_grp(options->len_grp, grp_pwd->gr_name);
	else //if !group_name display group ID
        display_number(options->len_grp, ft_itoa(f_stat.st_gid));
}


void    display_number(long long int max, char *str)
{
    char    *lnk;
    int     i;
    int     j;

    i = max + 1;
    j = ft_strlen(str);
    if (!(lnk = ft_memalloc(max + 2)))
        return ;
    lnk[max + 1] = '\0';
    while (j >= 0)
    {
        lnk[i] = str[j];
        i--;
        j--;
    }
    i++;
    while (--i >= 0)
        lnk[i] = ' ';
    ft_putstr(lnk);
    ft_putchar(' ');
    ft_strdel(&lnk);
    ft_strdel(&str);
}

void    major_minor_dev_number(dev_t dev_id)
{
    ft_putnbr((int)major(dev_id));
    ft_putstr(", ");
    ft_putnbr((int)minor(dev_id));
    ft_putchar(' ');
}

void        display_usr_grp(unsigned short max, char *str)
{
    int     i;
    char    *tmp;

    i = 0;
    if (!(tmp = ft_memalloc(max + 2)))
        return ;
    ft_strcpy(tmp, str);
    i = ft_strlen(str);
    while (i < max)
    {
        tmp[i] = ' ';
        i++;
    }
    ft_putstr(tmp);
    ft_putchar(' ');
    ft_strdel(&tmp);
}