/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:29:28 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/16 13:41:52 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	basic_sort_lst(t_file **lst)
{
	t_file		*ptr;
	t_file		*next_ptr;
	char		*tmp;

	ptr = *lst;
	next_ptr = (*lst)->next;
	while (ptr->next)
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
	ptr = *lst;
	next_ptr = (*lst)->next;
	while (ptr->next && ft_strcmp(ptr->name, ptr->next->name) < 0)
	{
		ptr = ptr->next;
		next_ptr = ptr->next;			
	}
	if (ptr->next)
		basic_sort_lst(lst);
}//31 Lignes (2fix)

// void	sort_reverse(t_stlist *dblist);

// void	sort_time(t_stlist *dblist);