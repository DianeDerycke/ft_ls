/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:29:28 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/30 13:53:06 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	sort_time(t_file **lst)
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
	while (ptr->next && ft_strcmp(ptr->name, ptr->next->name) < 0)
		ptr = ptr->next;
	if (ptr->next)
		basic_sort_lst(lst);

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
	while (ptr->next && ft_strcmp(ptr->name, ptr->next->name) < 0)
		ptr = ptr->next;
	if (ptr->next)
		basic_sort_lst(lst);
}