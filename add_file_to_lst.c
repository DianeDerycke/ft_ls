/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:18:08 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/10 14:50:06 by DERYCKE          ###   ########.fr       */
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

void		push_back(t_stlist *dblist, char *str)
{
	t_file	*new;

	new = (t_file *)malloc(sizeof(t_file));
	if (!new)
   		return ;
	new->name = ft_strdup(str);
	new->prev = dblist->last;
	new->next = NULL;
	if (dblist->last)
		dblist->last->next = new;
	else 
		dblist->first = new;
   dblist->last = new;
}

void	add_current_dir(t_stlist *dblist, const char *path)
{
	DIR 			*openf;
	struct dirent	*readf;
	char			*tmp;
	t_file			*lst;

	tmp = NULL;
	readf = NULL;
	lst = dblist->first;
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
	if (!argv[i] || (ft_strcmp(argv[i], ".") == 0))
		add_current_dir(dblist, NULL);
	else
		while (argv[i])
		{
			if (!(file_exist(argv[i])))
				error_no_file_or_dir(argv[i]);
			push_back(dblist, argv[i]);
			i++;
		}
	basic_sort_lst(dblist);
}