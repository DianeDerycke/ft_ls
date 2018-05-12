/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 22:50:39 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
void	apply_opt(t_stlist *dblist, t_opt *options)
{
	if (options->t)
		option_sort_time(dblist);
	if (options->r)
		option_sort_reverse(dblist);
	if (options->l)
	{
		while (dblist->first->next)
		{
			option_l(dblist, options);
			dblist->first = dblist->first->next;
		}
	}
}

void		read_directory(char *path, t_opt *options)
{
	t_stlist		*tmp;
	DIR 			*openf;
	struct dirent 	*readf;
	char			*tmp1;

	tmp1 = NULL;
	openf = opendir(path);
	if (!(tmp = ft_memalloc(sizeof(t_stlist))))
		return ;
	while((readf = readdir(openf)))
		push_back(tmp, readf->d_name);
	basic_sort_lst(tmp);
	display_dir(tmp, path, options);
	closedir(openf);
	if (options->big_r)
	{
		if (!(new_path = find_next_dir(tmp, options)))
			new_path = find_next_dir(tmp = tmp->next, options);
		read_directory(new_path, options);
	}
}

void	for_each_node(t_opt *options, t_stlist *dblist)
{
		while (dblist->first)
	{
		read_directory(dblist->first->name, options);
		dblist->first = dblist->first->next;
	}
}