/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/07 18:33:33 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

static char		*define_path(char *path, char *name)
{
	if (path[0] == '/' && ft_strlen(path) == 1)
		return (ft_strjoin(ft_strdup(path), name));
	else
		return (create_path(path, name));
}

void			recursive(t_file *subdir, char *path, t_opt *options)
{
	char	*newpath;

	newpath = NULL;
	while (subdir)
	{
		if (ft_strcmp(subdir->name, ".") != 0 && ft_strcmp(subdir->name, "..") != 0)
		{
			newpath = define_path(path, subdir->name);
			if (is_dir(newpath))
			{
				if (!(is_lnk(newpath)) && options->argc != 1)
					display_dir_path(newpath);
				read_args(newpath, options);
			}
			free(newpath);
		}
		subdir = subdir->next;
	}
}

void			read_args(char *path, t_opt *options)
{
	DIR 			*openf;
	struct dirent 	*readf;
	t_file			*subdir;

	subdir = NULL;
	if (!(openf = opendir(path)))
		return;
	while ((readf = readdir(openf)) != NULL)
	{
		if (options->a != 1 && readf->d_name[0] == '.')
			continue ;
		if (push_back(&subdir, readf->d_name) < 0)
			return ;
	}
	closedir(openf);
	sort_display(&subdir, path, options);
	if (options->big_r)
		recursive(subdir, path, options);
	free_lst(&subdir);
}