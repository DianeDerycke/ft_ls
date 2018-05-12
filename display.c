/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 17:55:15 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	basic_display(t_file *lst, t_opt *options)
{
	t_file 	*tmp;

	tmp = lst;
	while(tmp->next && options->a == 0 && tmp->name[0] == '.')
		tmp = tmp->next;
	while (tmp)
	{
		printf("%s\n", tmp->name);
		if (tmp->next)
			tmp = tmp->next;
		else
			break;
	}
}

void	display_dir(t_stlist *dblist, char *path, t_opt *options)
{
	while (dblist->first->next && options->a == 0 && dblist->first->name[0] == '.')
		dblist->first = dblist->first->next;
	printf("%s%s\n", path, ":");
	while (dblist->first)
	{
		printf("%s\n", dblist->first->name);
		dblist->first = dblist->first->next;
	}
}