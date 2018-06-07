/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:29:32 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/07 11:22:09 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		push_back(t_file **lst, char *str)
{
	t_file	*new;
	t_file	*tmp;

	if ((*lst))
	{
		tmp = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		if (!(new = ft_memalloc(sizeof(t_file))))
			return (-1);
		(*lst)->next = new;
		new->name = ft_strdup(str);
		new->prev = *lst;
		new->next = NULL;
		*lst = tmp;
	}
	else
	{
		if (!((*lst) = init_lst()))
			return (-1);
		tmp = NULL;
		new = NULL;
		(*lst)->name = ft_strdup(str);
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
	}
	return (0);
} //27 lignes


void	free_lst(t_file	**subdir)
{
	t_file	*tmp;

	tmp = NULL;
	while ((*subdir))
	{
		tmp = (*subdir)->next;
		free((*subdir)->name);
		free((*subdir)->path);
		free(*subdir);
		*subdir = tmp;
	}
}
