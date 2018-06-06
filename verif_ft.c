/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:41:33 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/06 21:46:40 by DERYCKE          ###   ########.fr       */
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

void	get_data_file(t_file **dir, char *path)
{
	t_file			*tmp;
	struct stat 	file_stat;

	tmp = *dir;
	while (*dir)
	{
		(*dir)->path = create_path(path, (*dir)->name);
		if (lstat((*dir)->path, &file_stat) < 0)
			return ;
		(*dir)->upd_time = file_stat.st_mtime;
		*dir = (*dir)->next;
	}
	*dir = tmp;
}