/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:41:33 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/17 04:24:42 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int 	file_exist(const char *path)
{
  struct stat   buffer;

  if (lstat(path, &buffer) == 0)
  	return (1);
  else if (stat(path, &buffer) == 0)
  	return (1);
  return (0);
}

int		is_stat_dir(const char *path) 
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int		is_lstat_dir(const char *path) 
{
	struct stat statbuf;

	if (lstat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}


int		is_lnk(const char *path)
{
	struct stat statbuf;

	if (lstat(path, &statbuf) != 0)
		return (0);
	return (S_ISLNK(statbuf.st_mode));
}

void	get_data_file(t_file **dir, char *path)
{
	t_file			*ptr;
	struct stat 	file_stat;

	ptr = *dir;
	while (ptr)
	{
		if (*path)
			ptr->path = create_path(path, ptr->name);
		if (lstat(ptr->path, &file_stat) < 0)
			return ;
		ptr->upd_time = file_stat.st_mtimespec;
		ptr = ptr->next;
	}
}

char		*define_path(char *path, char *name)
{
	if (path[0] == '/' && ft_strlen(path) == 1)
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