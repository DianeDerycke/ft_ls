/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:41:33 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/21 13:05:18 by DERYCKE          ###   ########.fr       */
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
		ptr->path = define_path(path, ptr->name);
		if (lstat(ptr->path, &file_stat) < 0)
			return ;
		ptr->upd_time = file_stat.st_mtimespec;
		ptr = ptr->next;			
	}
}

char		*define_path(char *path, char *name)
{
	if (name[0] == '/')
		return (ft_strdup(name));
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

int 		treat_arg(t_file *lst, t_opt *options)
{
	t_file		*tmp;

	tmp = lst;
	if (!lst)
		return (EXIT_FAILURE);
	apply_right_sort(&lst, ".", options);
	while (lst)
	{
		if (is_stat_dir(lst->name) || (is_lnk(lst->name)))
		{
			if (options->nb_file)
				display_dir_path(lst->name);
			if (read_args(lst->name, lst->name, options) == 1)
				return (EXIT_FAILURE);
			if (lst->next)
				ft_putchar('\n');			
		}
		lst = lst->next;
	}
	lst = tmp;
	free_lst(&tmp);
	return (EXIT_SUCCESS);
}