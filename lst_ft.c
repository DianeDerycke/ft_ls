/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:29:32 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/11 19:01:53 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

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

int			add_lst_curr_pos(t_file *lst, t_stlist *dblist, char *str)
{
	t_file 	*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (-1);
	if (!(lst->next))
		push_back(dblist, str);
	else
	{
		new->name = ft_strdup(str);
		new->next = lst->next;
		new->prev = lst;
		lst->next = new;
		lst->next->prev = new;
	}
	return (0);
}