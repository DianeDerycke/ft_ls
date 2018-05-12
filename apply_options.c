/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 15:19:43 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
void	apply_opt(t_stlist	*dblist, t_opt *options)
{
	while (dblist->first->next)
	{
		if (options->t)
			option_sort_time(dblist);
		if (options->r)
			option_sort_reverse(dblist);
		if (options->l)
			option_l(dblist, options);
		dblist->first = dblist->first->next;
	}
}

void		manage_data_sub(char *path, char *sub_path, t_opt *options)
{
	t_stlist		*tmp;
	DIR 			*openf;
	struct dirent 	*readf;

	if (!(tmp = ft_memalloc(sizeof(t_stlist))))
		return ;
	openf = opendir(path);
	while ((readf = readdir(openf)))
	{
		push_back(tmp, readf->d_name);
	}
	display_dir(tmp, path, sub_path, options);
	free(tmp);
	if (options->big_r == 1)
	{
		while ((readf = readdir(openf)))
		{
			sub_path = ft_strjoin(path, "/");
			sub_path = ft_strjoin(sub_path, readf->d_name);
			if (is_dir(sub_path) && readf->d_name[0] != '.')
				manage_data_sub(path, sub_path, options);
		}
		closedir(openf);
	}
}

void	for_each_node(t_opt *options, t_stlist *dblist)
{
	basic_display(dblist->first, options);
	while (dblist->first)
	{
		if (is_dir(dblist->first->name) && dblist->first->name[0] != '.')
			manage_data_sub(dblist->first->name, NULL, options);
		dblist->first = dblist->first->next;
	}
}