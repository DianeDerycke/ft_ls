/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:41:33 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/17 19:16:45 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	get_data_file(t_file **dir, char *path)
{
	t_file			*ptr;
	struct stat 	file_stat;

	ptr = *dir;
	while (ptr)
	{
		if (*path)
			ptr->path = define_path(path, ptr->name);
		if (lstat(ptr->path, &file_stat) < 0)
			return ;
		ptr->upd_time = file_stat.st_mtimespec;
		ptr = ptr->next;
	}
}

char		*define_path(char *path, char *name)
{
	if (path[ft_strlen(path) - 1] == '/')
		return (ft_strjoin(ft_strdup(path), name));
	return (create_path(path, name));
}

char	*create_path(char *path, char *dirname)
{
	char	*newpath;
	char	*tmp;

	if (!(tmp = ft_strdup(path)))
		return (NULL);
	if (!(newpath = ft_strjoin(tmp, "/")) || 
		!(tmp = ft_strjoin(newpath, dirname)))
		return (NULL);
	return (tmp);
}

int 		treat_arg(t_file *lst, char **argv, int n, t_opt *options)
{
	t_file		**tmp;

	tmp = &lst;
	while (lst)
	{
		if (is_stat_dir(lst->name) || is_lnk(lst->name))
		{
			if (argv[n+1])
				display_dir_path(lst->name);
			if (read_args(lst->name, lst->name, options) < 0)
				return (-1);
			if (lst->next)
				ft_putchar('\n');			
		}
		lst = lst->next;		
	}
	free_lst(tmp);
	return (0);
}