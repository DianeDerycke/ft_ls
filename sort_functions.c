/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:29:28 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/11 18:28:49 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	basic_sort_lst(t_stlist *lst)
{
	t_file		*ptr;
	t_file		*next_ptr;
	char		*tmp;

	ptr = lst->first;
	next_ptr = lst->first->next;
	while (ptr->name != lst->last->name)
	{
		if (ft_strcmp(ptr->name, next_ptr->name) > 0)
		{
			tmp = ptr->name;
			ptr->name = next_ptr->name;
			next_ptr->name = tmp;
		}
		ptr = ptr->next;
		next_ptr = ptr->next;
	}
	ptr = lst->first;
	next_ptr = lst->first->next;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->name, next_ptr->name) <= 0)
		{
			ptr = ptr->next;
			next_ptr = ptr->next;			
		}
		else
			break;
	}
	if (ptr->name != lst->last->name)
		basic_sort_lst(lst);
}//31 Lignes (2fix)

// void	sort_reverse(t_stlist *dblist);

// void	sort_time(t_stlist *dblist);