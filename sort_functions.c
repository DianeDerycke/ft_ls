/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:29:28 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/03 23:21:46 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	sort_time(t_file **lst)
{
	t_file		*ptr;
	t_file		*next_ptr;
	size_t		tmp;

	ptr = *lst;
	next_ptr = ptr->next;
	tmp = 0;
	while (ptr->next)
	{
		if (ptr->upd_time < next_ptr->upd_time)
		{
			tmp = ptr->upd_time;
			ptr->upd_time = next_ptr->upd_time;
			next_ptr->upd_time = tmp;
		}
		ptr = ptr->next;
		next_ptr = ptr->next;
	}
	ptr = *lst;
	while (ptr->next && ptr->upd_time > ptr->next->upd_time)
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
	t_file		*next_ptr;
	t_file		*tmp;

	ptr = *lst;
	next_ptr = (*lst)->next;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->name, ptr->next->name) > 0)
			//swap content ou swap ptr
		ptr = ptr->next;
	}
	ptr = *lst;
	while (ptr->next && ft_strcmp(ptr->name, ptr->next->name) < 0)
		ptr = ptr->next;
	if (ptr->next)
		basic_sort_lst(lst);
}