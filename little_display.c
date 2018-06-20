/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:18:39 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/21 01:22:53 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_link(char *path, char *filename)
{
	char	tmp[1024];
	int		buffsize;

	if ((buffsize = readlink(path, tmp, sizeof(tmp) - 1)) != -1)
		tmp[buffsize] = '\0';
	ft_putstr(filename ? filename : path);
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

void	display_error_files(t_file **lst, t_opt *options)
{
	t_file	*files;

	files = *lst;
	if (files)
	{
		options->nb_file++;
		basic_sort_lst(&files);
		while (files)
		{
			error_no_file_or_dir(files->name);
			files = files->next;
		}
		*lst = files;
		free_lst(lst);
	}
}