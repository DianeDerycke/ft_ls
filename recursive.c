/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/17 19:55:15 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void			recursive(t_file *subdir, char *path, t_opt *options)
{
	char	*newpath;

	newpath = NULL;
	while (subdir)
	{
		if (ft_strcmp(subdir->name, ".") == 0 || 
			ft_strcmp(subdir->name, "..") == 0)
		{
			subdir = subdir->next;
			continue ;
		}
		newpath = define_path(path, subdir->name);
		if (is_lstat_dir(newpath))
		{
			ft_putchar('\n');
			display_dir_path(newpath);
			read_args(subdir->name, newpath, options);
		}
		ft_strdel(&newpath);
		subdir = subdir->next;
	}
}

int			read_args(char *filename, char *path, t_opt *options)
{
	DIR 			*openf;
	struct dirent 	*readf;
	t_file			*subdir;

	subdir = NULL;
	if (!(openf = opendir(path)))
		return (perm_denied(filename));
	while ((readf = readdir(openf)) != NULL)
	{
		if (options->a != 1 && readf->d_name[0] == '.')
			continue ;
		push_back(&subdir, readf->d_name);
	}
	closedir(openf);
	apply_right_sort(&subdir, path, options);
	display_content_dir(subdir, options);
	if (options->big_r)
		recursive(subdir, path, options);
	free_lst(&subdir);
	return (1);
}