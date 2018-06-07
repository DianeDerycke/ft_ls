/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:29:28 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/07 22:05:51 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void			swap_content(t_file **ptr, t_file **next)
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

// static void		sort_lexico(t_file **lst)
// {
// 	size_t		time;
// 	t_file		*ptr;
// 	t_file		*tmp;

// 	ptr = *lst;
// 	time = ptr->upd_time;
// 	while (ptr && ptr->upd_time == time)
// 	{
// 		if (ptr->next && ptr->next->upd_time == time)
// 			ptr = ptr->next;
// 		else
// 			break;
// 	}
// 	tmp = ptr->next;
// 	ptr->next = NULL;
// 	ptr = *lst;
// 	basic_sort_lst(&ptr);
// 	while (ptr)
// 		ptr = ptr->next;
// 	ptr->next = tmp;
// 	if (tmp)
// 		sort_lexico(&tmp);
// }

void			sort_time(t_file **lst)
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
	if  (ptr->next)
		sort_time(lst);
	// else
	// 	sort_lexico(lst);
}

void			sort_args(char **argv, t_opt *options)
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

void			reverse_sort(t_file **lst)
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


void			basic_sort_lst(t_file **lst)
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