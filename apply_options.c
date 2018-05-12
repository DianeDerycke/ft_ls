/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 12:15:35 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
void	apply_opt(t_stlist	*dblist, t_opt *options)
{
	while (dblist->first)
	{
		if (options->t)
			option_sort_time(dblist);
		if (options->r)
			option_sort_reverse(dblist);
		if (option->l)
		{
			option_l(dblist, options);
			
		}
	}
}

void	recursive(char *path)
{
	DIR 	*openf;
	char	*tmp;

	tmp = NULL;
	openf = opendir(path);
	while ((readf= readdir(openf)))
	{
		if (is_dir(readf->d_name))
		{

			tmp = ft_strjoin(path, readf->name);
			manage_data_sub(tmp);
		}
	}
	closedir(openf);
}

int		manage_data_sub(char *path, t_opt *options)
{
	t_stlist	*tmp;
	DIR 	*openf;

	if (!(tmp = ft_memalloc(sizeof(t_stlist))))
		return (-1);
	openf = opendir(path);
	while ((readf = readdir(openf)))
	{
		push_back(tmp, readf->d_name);
		apply_opt(tmp, options)
		apply_right_display(t_stlist *dblist);
	}
	closedir(openf);
	recursive(path);
}

int		for_each_node(t_opt *options, t_stlist *dblist)
{
	DIR 	*openf;

	while (dblist->first)
	{
		if (is_dir(dblist->first->name))
			if (manage_data_sub(dblist->first->name, options) < 0)
				return (-1);
		dblist->first = dblist->first->next;
	}
	return (0);
}