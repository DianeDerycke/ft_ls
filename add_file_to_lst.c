/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:18:08 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 12:08:30 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stlist	*init_dblist(void)
{
	t_stlist 	*dblst;

	if (!(dblst = ft_memalloc(sizeof(t_stlist))))
		return (NULL);
	return (dblst);
}

void	add_current_dir(t_stlist *dblist, char *path)
{
	DIR 			*openf;
	struct dirent	*readf;
	char			*tmp;

	tmp = NULL;
	if (!path)
		openf = opendir(".");
	else
		openf = opendir(path);
	while ((readf = readdir(openf)))
	{	
		tmp = ft_memalloc(ft_strlen(readf->d_name) + 1);
		tmp = ft_strcpy(tmp, readf->d_name);
		push_back(dblist, tmp);
		free(tmp);
		tmp = NULL;
	}
	closedir(openf);
}

void	add_file_to_lst(char **argv, t_stlist *dblist)
{
	int				i;

	i = 0;
	if (!argv[i])
		argv[i] = ft_strdup(".");
	while (argv[i])
	{
		if (!(file_exist(argv[i])))
			error_no_file_or_dir(argv[i]);
		push_back(dblist, argv[i]);
		i++;
	}
	basic_sort_lst(dblist);
}