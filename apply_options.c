/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 17:56:54 by DERYCKE          ###   ########.fr       */
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

void		manage_data_sub(char *path, t_opt *options)
{
	t_stlist		*tmp;
	DIR 			*openf;
	struct dirent 	*readf;
	char			*tmp1;

	tmp1 = ft_strdup(path);
	openf = opendir(path);
	if (!(tmp = ft_memalloc(sizeof(t_stlist))))
		return ;
	while((readf = readdir(openf)))
		push_back(tmp, readf->d_name);
	display_dir(tmp, path, options);
	closedir(openf);
	// ft_pause();
	if (options->big_r == 1)
	{
		path = ft_strjoin(tmp1, "/");
		openf = opendir(path);
		while ((readf = readdir(openf)))
		{
			if (readf->d_name[0] != '.')
				manage_data_sub((path = ft_strjoin(path, readf->d_name)), options);
		}
	}
}

void	for_each_node(t_opt *options, t_stlist *dblist)
{
	// basic_display(dblist->first, options);
	while (dblist->first)
	{
		if (is_dir(dblist->first->name))
			manage_data_sub(dblist->first->name, options);			
		dblist->first = dblist->first->next;
	}
}