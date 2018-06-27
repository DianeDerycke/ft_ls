/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:29:28 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/27 08:27:10 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		apply_right_sort(t_file **lst, char *path, t_opt *options)
{
	get_data_file(lst, path);
	if (options->t && *lst)
		sort_time(lst);
	else if (*lst)
		lexico_sort(lst);
	if (options->r && *lst)
		reverse_sort(lst);
}

void		reverse_sort(t_file **lst)
{
	t_file		*current;
	t_file		*prev;
	t_file		*next;

	current = *lst;
	prev = NULL;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*lst = prev;
}

void		lexico_sort(t_file **lst)
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
		lexico_sort(lst);
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
