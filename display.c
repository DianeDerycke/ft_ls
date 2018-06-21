/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/21 12:58:02 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_content_dir(t_file *lst, t_opt *options)
{
	if (options->l && !options->one && lst)
	{
		if (find_max_for_each(lst, options) == 0)
			display_total_size(options->d_size);
		while (lst)
		{
			long_format(lst->path, lst->name, options);
			lst = lst->next;
		}
	}
	else 
		while (lst)
		{
			ft_putendl(lst->name);
			lst = lst->next;
		}
	reset_options(options);
}

void	display_files(t_file *lst, t_file **files, t_opt *options)
{
	t_file			*ptr;

	ptr = *files;
	options->nb_file++;
	while (ptr)
	{
		if (options->l && !options->one)
		{
			find_max_for_each(ptr, options);
			long_format(ptr->name, ptr->name, options);
		}
		else
			ft_putendl(ptr->name);
		ptr = ptr->next;
	}
	if (lst)
		ft_putchar('\n');
	free_lst(files);
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

void        display_usr_grp(unsigned short max, char *str)
{
	int		i;
	char	*tmp;

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