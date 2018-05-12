/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:29:32 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 21:06:10 by DERYCKE          ###   ########.fr       */
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