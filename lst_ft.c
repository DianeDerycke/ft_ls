/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:29:32 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/16 00:40:52 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		push_back(t_file **lst, char *str)
{
	t_file	*new;
	t_file	*tmp;

	new = NULL;
	tmp = NULL;
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
		(*lst)->next = NULL;
		(*lst)->name = ft_strdup(str);
	}
	return (0);
}

void 	delete_node(t_file *ptr)
{
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	else
		ptr->next = NULL;
	if (ptr->prev)
		ptr->prev->next = ptr->next;
	else
		ptr->prev = NULL;
	free(ptr->name);
	free(ptr->path);
	free(ptr);
}

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
