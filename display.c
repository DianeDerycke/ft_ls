/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/18 19:06:32 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_content_dir(t_file *lst, t_opt *options)
{
	if (options->l && !options->one)
	{
		if (find_max_for_each(lst, options) == 0)
			display_total_size(options);
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

void	display_files(t_file **lst, t_opt *options)
{
	t_file			*ptr;

	ptr = *lst;
	while (ptr)
	{
		if (!(is_stat_dir(ptr->name)))
		{
			(options->nb_file)++;
			if (options->l && !options->one)
				long_format(ptr->name, ptr->name, options);
			else
				ft_putendl(ptr->name);
			delete_node(ptr);
		}
		else
			options->nb_dir++;
		ptr = ptr->next;
	}
	if (options->nb_dir && options->nb_file)
	{
		options->nb_dir = 0;
		options->nb_file = 0;
		ft_putchar('\n');
	}
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