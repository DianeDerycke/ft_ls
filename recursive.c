/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/16 11:56:16 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

char		*define_path(char *path, char *name)
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
				{
					ft_putchar('\n');
					display_dir_path(newpath);
				}
				read_args(subdir->name, newpath, options);
			}
			free(newpath);
		}
		subdir = subdir->next;
	}
}

int			read_args(char *filename, char *path, t_opt *options)
{
	DIR 			*openf;
	struct dirent 	*readf;
	t_file			*subdir;

	subdir = NULL;
	if ((openf = opendir(path)) == NULL)
	{
		perm_denied(filename, path);
		return (-1);
	}
	while ((readf = readdir(openf)) != NULL)
	{
		if (options->a != 1 && readf->d_name[0] == '.')
			continue ;
		if (push_back(&subdir, readf->d_name) < 0)
			return (-1);
	}
	closedir(openf);
	apply_right_sort(&subdir, path, options);
	display_content_dir(subdir, options);
	if (options->big_r)
		recursive(subdir, path, options);
	free_lst(&subdir);
	return (1);
}