/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:27:21 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/25 14:50:07 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		file_exist(const char *path)
{
	struct stat		buffer;

	if (lstat(path, &buffer) == 0 || stat(path, &buffer) == 0)
		return (1);
	return (0);
}

int		is_stat_dir(const char *path)
{
	struct stat		statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int		is_lstat_dir(const char *path)
{
	struct stat		statbuf;

	if (lstat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int		is_lnk(const char *path)
{
	struct stat		statbuf;

	if (lstat(path, &statbuf) != 0)
		return (0);
	return (S_ISLNK(statbuf.st_mode));
}
