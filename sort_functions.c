/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:29:28 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/21 00:15:23 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int			swap_content(t_file **ptr, t_file **next)
{
	t_file		*tmp;

	if (!(tmp = init_lst()))
		return (0);
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
	return (1);
}

void		apply_right_sort(t_file **lst, char *path, t_opt *options)
{
	get_data_file(lst, path);
	if (options->t && *lst)
		sort_time(lst);
	else if (*lst)
		basic_sort_lst(lst);
	if (options->r && *lst)
		reverse_sort(lst);
}

void		reverse_sort(t_file **lst)
{
    t_file		*prev;
    t_file		*current;
    t_file		*next;

    prev = NULL;
    current = *lst;
    next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *lst = prev;
}

void		basic_sort_lst(t_file **lst)
{
	t_file		*ptr;

	ptr = *lst;
	while (ptr->next)
	{
		if (*(ptr->name) && ft_strcmp(ptr->name, ptr->next->name) > 0)
			swap_content(&ptr, &(ptr->next));
		ptr = ptr->next;
	}
	ptr = *lst;
	while (ptr->next && ft_strcmp(ptr->name, ptr->next->name) <= 0)
		ptr = ptr->next;
	if (ptr->next)
		basic_sort_lst(lst);
}

void		sort_time(t_file **lst)
{
	t_file				*curr;
	int					swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		curr = *lst;
		while (curr->next)
		{
			if (curr->upd_time.tv_sec < curr->next->upd_time.tv_sec)
				swap = swap_content(&curr, &(curr->next));
			else if (curr->upd_time.tv_sec == curr->next->upd_time.tv_sec)
			{
				if (curr->upd_time.tv_nsec < curr->next->upd_time.tv_nsec || 
					(curr->upd_time.tv_nsec == curr->next->upd_time.tv_nsec 
						&& ft_strcmp(curr->name, curr->next->name) > 0))
					swap = swap_content(&curr, &(curr->next));
			}
			curr = curr->next;
		}
	}
}
