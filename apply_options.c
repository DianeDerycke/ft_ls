/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/17 22:32:14 by DERYCKE          ###   ########.fr       */
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
			newpath = ft_strdup(path);
			tmp = ft_strjoin(newpath, "/");
			newpath = ft_strjoin(tmp, subdir->name);
		if (is_dir(newpath))
			read_args(newpath, options);
		free(newpath);
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
		if (push_back(&subdir, readf->d_name) < 0)
			return ;
	closedir(openf);
	basic_sort_lst(&subdir);
	display_dir(subdir, path, options);
	if (options->big_r)
		recursive(subdir, path, options);
	free_lst(&subdir);
}