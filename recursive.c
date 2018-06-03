/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/03 21:07:10 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	recursive(t_file *subdir, char *path, t_opt *options)
{
	char	*tmp;
	char	*newpath;

	tmp = NULL;
	newpath = NULL;
	while (subdir)
	{
		if (ft_strcmp(subdir->name, ".") != 0 && ft_strcmp(subdir->name, "..") != 0)
		{
			if (path[0] == '/' && ft_strlen(path) == 1)
			{
				tmp = ft_strdup(path);
				newpath = ft_strjoin(tmp, subdir->name);
			}
			else
				newpath = create_path(path, subdir->name);
			if (is_dir(newpath))
			{
				if (!(is_lnk(newpath)) && options->argc != 1)
				{
					ft_putchar('\n');
					ft_putstr(newpath);
					ft_putstr(":\n");				
				}
				read_args(newpath, options);
				free(newpath);
			}
		}
		subdir = subdir->next;
	}
}

void	read_args(char *path, t_opt *options)
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