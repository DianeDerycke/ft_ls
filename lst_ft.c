/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:29:32 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/21 12:59:43 by DERYCKE          ###   ########.fr       */
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
			malloc_error();
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

void 	delete_node(t_file *elem)
{
	if (elem->next)
		elem->next->prev = elem->prev;
	else
		elem->next = NULL;
	if (elem->prev)
		elem->prev->next = elem->next;
	else
		elem->prev = NULL;
	ft_strdel(&(elem->name));
	ft_strdel(&(elem->path));
	free(elem);
}

void	free_lst(t_file	**lst)
{
	t_file	*tmp;

	tmp = NULL;
	while ((*lst))
	{
		tmp = (*lst)->next;
		ft_strdel(&(*lst)->name);
		ft_strdel(&(*lst)->path);
		free(*lst);
		*lst = tmp;
	}
}

void		add_file_to_lst(char **argv, t_file **lst, t_opt *options)
{
	int 	i;
	t_file		*tmp;
	t_file		*files;

	i = -1;
	tmp = NULL;
	files = NULL;
	while (argv[++i])
	{
		if ((file_exist(argv[i]) && !(is_stat_dir(argv[i]))) || 
			(is_lnk(argv[i]) && options->l == 1))
			push_back(&files, argv[i]);
		else if (!(file_exist(argv[i])))
			push_back(&tmp, argv[i]);
		else
			push_back(lst, argv[i]);
	}
	display_error_files(&tmp, options);
	if (files)
	{
		apply_right_sort(&files, ".", options);
		display_files(*lst, &files, options);	
	}
	if (*lst && (*lst)->next)
		options->nb_file++;
}
