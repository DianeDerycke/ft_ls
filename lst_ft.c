/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:29:32 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/17 19:18:27 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void		push_back(t_file **lst, char *str)
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
			MALLOC_ERROR;
		(*lst)->next = new;
		new->name = ft_strdup(str);
		new->prev = *lst;
		new->next = NULL;
		*lst = tmp;
	}
	else
	{
		*lst = init_lst();
		(*lst)->next = NULL;
		(*lst)->name = ft_strdup(str);
	}
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

void		add_file_to_lst(char **argv, t_file **lst)
{
	int 	i;

	i = -1;
	while (argv[++i])
	{
		if (file_exist(argv[i]))
			push_back(lst, argv[i]);
		else
			error_no_file_or_dir(argv[i]);			
	}
}
