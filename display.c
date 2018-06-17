/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/17 04:26:37 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_content_dir(t_file *lst, t_opt *options)
{
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
	t_file			*ptr;
	static int		nb_dir = 0;
	static int		nb_file = 0;

	ptr = *lst;
	while (ptr)
	{
		if (!(is_stat_dir(ptr->name)))
		{
			nb_file++;
			if (options->l && !options->one)
				long_format(ptr->name, ptr->name, options);
			else
				ft_putendl(ptr->name);
			delete_node(ptr);
		}
		else
			nb_dir++;
		ptr = ptr->next;
	}
	if (nb_dir && nb_file)
	{
		nb_dir = 0;
		nb_file = 0;
		ft_putchar('\n');
	}
}