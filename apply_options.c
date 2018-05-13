/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/13 03:14:41 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
void	apply_opt(t_stlist *dblist, t_opt *options)
{
	if (options->t)
		option_sort_time(dblist);
	if (options->r)
		option_sort_reverse(dblist);
	if (options->l)
	{
		while (dblist->first->next)
		{
			option_l(dblist, options);
			dblist->first = dblist->first->next;
		}
	}
}

void	recursive(char *path, t_opt *options, t_stlist *subdir)
{
	DIR 			*openf;
	struct dirent 	*readf;
	char	*newpath;
	char	*tmp;

	openf = opendir(path);
	while ((readf = readdir(openf)))
	{
		tmp = ft_strdup(path);
		newpath = ft_strjoin(tmp, readf->d_name);
		if (is_dir(newpath) && readf->d_name[0] != '.')
		{
			printf("\n%s%s\n", newpath, ":");
			read_directory(newpath, options, subdir);
		}
	}
}

void		read_directory(char *path, t_opt *options, t_stlist *subdir)
{
	DIR 			*openf;
	struct dirent 	*readf;
	char			*tmp;

	openf = opendir(path);
	tmp = ft_strdup(path);
	path = ft_strjoin(tmp, "/");
	if (!(subdir = ft_memalloc(sizeof(t_stlist))))
		return ;
	while((readf = readdir(openf)))
		push_back(subdir, readf->d_name);
	basic_sort_lst(subdir);
	display_dir(subdir, path, options);
	free(tmp);
	closedir(openf);
	if (options->big_r == 1)
		recursive(path, options, subdir);

}