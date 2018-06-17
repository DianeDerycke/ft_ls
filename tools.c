/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:41:33 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/17 13:28:26 by DERYCKE          ###   ########.fr       */
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
	else
		return (create_path(path, name));
}

char	*create_path(char *path, char *dirname)
{
	char	*newpath;
	char	*tmp;

	if ((!path || !dirname) || !(tmp = ft_strdup(path)))
		return (NULL);
	else if (!(newpath = ft_strjoin(tmp, "/")))
		return (NULL);
	else if (!(tmp = ft_strjoin(newpath, dirname)))
		return (NULL);
	return (tmp);
}