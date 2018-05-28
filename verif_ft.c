/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:41:33 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/25 17:04:51 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int 	file_exist(const char *path)
{
  struct stat   buffer;

  return (lstat(path, &buffer) == 0);
}

int		is_dir(const char *path) 
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