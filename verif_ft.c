/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:41:33 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/13 10:15:22 by DERYCKE          ###   ########.fr       */
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

int		usr_can_w(const char *path)
{
	struct stat statbuf;
	if (lstat(path, &statbuf) != 0 && !(S_IWUSR))
		return (0);
	return (1);
}