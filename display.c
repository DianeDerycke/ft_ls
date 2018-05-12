/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 20:59:26 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_dir(t_stlist *dblist, char *path, t_opt *options)
{
	(void)path;
	while (dblist->first->next && options->a == 0 && dblist->first->name[0] == '.')
		dblist->first = dblist->first->next;
	while (dblist->first)
	{
		printf("%s\n", dblist->first->name);
		dblist->first = dblist->first->next;
	}
}