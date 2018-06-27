/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 02:50:57 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/27 09:23:13 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_content_dir(t_file *lst, t_opt *options)
{
	if ((options->l || options->o || options->g) && !options->one && lst)
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
			insert_color(lst->path, options->big_g);
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
		if ((options->l || options->o || options->g) && !options->one)
		{
			find_max_for_each(ptr, options);
			long_format(ptr->name, ptr->name, options);
		}
		else
		{
			insert_color(ptr->path, options->big_g);
			ft_putendl(ptr->name);
		}
		ptr = ptr->next;
	}
	if (lst)
		ft_putchar('\n');
	free_lst(files);
}

void	display_link(char *path, char *filename, int big_g)
{
	char			tmp[1024];
	int				buffsize;

	if ((buffsize = readlink(path, tmp, sizeof(tmp) - 1)) != -1)
		tmp[buffsize] = '\0';
	if (big_g == 1)
		ft_putstr(MAGENTA);
	ft_putstr(filename);
	if (big_g == 1)
		ft_putstr(RESET);
	ft_putstr(" -> ");
	ft_putstr(tmp);
	ft_putchar('\n');
}

void	display_total_size(int total_size)
{
	ft_putstr("total ");
	ft_putnbr(total_size);
	ft_putchar('\n');
}

void	display_dir_path(char *str)
{
	ft_putstr(str);
	ft_putendl(":");
}
