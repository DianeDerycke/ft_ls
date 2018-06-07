/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/07 13:50:53 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	sort_display(t_file **lst, char *path, t_opt *options)
{
	if (*lst)
	{
		get_data_file(lst, path);
		if (options->t)
			sort_time(lst);
		else
			basic_sort_lst(lst);
		if (options->r)
			reverse_sort(lst);
		display_dir(*lst, path, options);
	}
}

void	display_dir(t_file *lst, char *path, t_opt *options)
{
	if ((is_dir(path) || is_lnk(path)) && options->argc == 1)
	{
		ft_putchar('\n');
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (options->l)
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

void	display_files(char **argv, t_opt *options)
{
	int		i;
	struct stat 	file_stat;

	i = 0;
	while (argv[i])
	{
		if (!(file_exist(argv[i])))
			error_no_file_or_dir(argv[i]);
		i++;
	}
	i = 0;
	while (argv[i])
	{
		if (file_exist(argv[i]) && !(is_dir(argv[i])))
		{
		    if (lstat(argv[i],&file_stat) < 0)
		        return ;
			if (options->l)
				long_format(argv[i], argv[i], options);
			else if (!(S_ISLNK(file_stat.st_mode)))
				ft_putendl(argv[i]);
		}
		i++;
	}
}