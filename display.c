/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/15 15:47:54 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_content_dir(t_file *lst, t_opt *options)
{
	if (!lst)
		return ;
	if (options->l && !options->one)
	{
		if (find_max_for_each(lst, options) > 0)
			display_total_size(options);
		while (lst)
		{
			long_format(lst->path, lst->name, options);
			lst = lst->next;
		}
	}
	else
		while (lst)
		{
			ft_putendl(lst->name);
			lst = lst->next;
		}
	reset_options(options);
}

void	display_files(t_file **lst, t_opt *options)
{
	struct stat 	file_stat;
	t_file			*ptr;

	ptr = *lst;
	while (ptr)
	{
		if (!(file_exist(ptr->name)))
			error_no_file_or_dir(ptr->name);
		ptr = ptr->next;
	}
	ptr = *lst;
	while (ptr)
	{
		if (file_exist(ptr->name) && !(is_dir(ptr->name)))
		{
		    if (lstat(ptr->name,&file_stat) < 0)
		        return ;
			if (options->l && !options->one)
				long_format(ptr->name, ptr->name, options);
			else if (!(S_ISLNK(file_stat.st_mode)))
			{
				ft_putendl(ptr->name);
				delete_node(ptr);
			}
		}
		ptr = ptr->next;
	}
}


