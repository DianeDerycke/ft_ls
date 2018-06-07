/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:29:28 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/07 10:50:44 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	swap_content(t_file **ptr, t_file **next)
{
	t_file		*tmp;

	if (!(tmp = init_lst()))
		return ;
	tmp->name = (*ptr)->name;
	tmp->path = (*ptr)->path;
	tmp->upd_time = (*ptr)->upd_time;
	(*ptr)->name = (*next)->name;
	(*ptr)->path = (*next)->path;
	(*ptr)->upd_time = (*next)->upd_time;
	(*next)->name = tmp->name;
	(*next)->path = tmp->path;
	(*next)->upd_time = tmp->upd_time;
	free(tmp);
}

void	sort_time(t_file **lst)
{
	t_file		*ptr;

	ptr = *lst;
	while (ptr->next)
	{
		if (ptr->upd_time < ptr->next->upd_time)
			swap_content(&ptr, &(ptr->next));
		ptr = ptr->next;
	}
	ptr = *lst;
	while (ptr->next && ptr->upd_time >= ptr->next->upd_time)
		ptr = ptr->next;
	if (ptr->next)
		sort_time(lst);
}

void	sort_args(char **argv, t_opt *options)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = i + 1;
	tmp = NULL;
	while (argv[j])
	{
		if (options->r != 1 ? ft_strcmp(argv[i], argv[j]) > 0 : 
			ft_strcmp(argv[i], argv[j]) < 0)
		{
			tmp = argv[i];
			argv[i] = argv[j];
			argv[j] = tmp;
		}
		i++;
		j++;
	}
	i = 0;
	while (argv[i + 1] && (options->r != 1 ? ft_strcmp(argv[i], argv[i + 1]) <= 0 : 
		ft_strcmp(argv[i], argv[i + 1]) >= 0))
		i++;
	if (argv[i + 1])
		sort_args(argv, options);
}

void	reverse_sort(t_file **lst)
{
    t_file		*prev;
    t_file		*current;
    t_file		*next;

    prev = NULL;
    current = *lst;
    next = NULL;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *lst = prev;
}


void	basic_sort_lst(t_file **lst)
{
	t_file		*ptr;

	ptr = *lst;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->name, ptr->next->name) > 0)
			swap_content(&ptr, &(ptr->next));
		ptr = ptr->next;
	}
	ptr = *lst;
	while (ptr->next && ft_strcmp(ptr->name, ptr->next->name) < 0)
		ptr = ptr->next;
	if (ptr->next)
		basic_sort_lst(lst);
}