/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:41:33 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/23 11:48:46 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void		get_data_file(t_file **dir, char *path)
{
	t_file			*ptr;
	struct stat 	file_stat;

	ptr = *dir;
	while (ptr)
	{
		ptr->path = create_path(path, ptr->name);
		if (lstat(ptr->path, &file_stat) < 0)
			return ;
		ptr->upd_time = file_stat.st_mtimespec;
		ptr = ptr->next;			
	}
}

char		*create_path(char *path, char *dirname)
{
	char 	*newpath;
	char	*tmp;

	newpath = NULL;
	tmp = NULL;
	if (dirname[0] == '/')
		return (ft_strdup(dirname));
	if (path[ft_strlen(path) - 1] == '/')
		return (ft_strjoin(ft_strdup(path), dirname));
	tmp = ft_strdup(path);
	newpath = ft_strjoin(tmp, "/");
	tmp = ft_strjoin(newpath, dirname);
	return (tmp);
}

void		insert_color(char *path)
{
	struct stat f_stat;
	mode_t 		mode;

	if (lstat(path, &f_stat) != 0)
		return ;
	mode = f_stat.st_mode;
	S_ISBLK(mode) ? ft_putstr(RED) : NULL;
	S_ISCHR(mode) ? ft_putstr(BLUE) : NULL;
	S_ISDIR(mode) ? ft_putstr(CYAN) : NULL;
	S_ISFIFO(mode) ? ft_putstr(YELLOW) : NULL;
	S_ISREG(mode) ? ft_putstr(RESET) : NULL;
	S_ISLNK(mode) ? ft_putstr(MAGENTA) : NULL;
	S_ISSOCK(mode) ? ft_putstr(GREEN) : NULL;
}