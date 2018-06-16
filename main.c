/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/16 11:58:01 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

static int		add_file_to_lst(char **argv, t_file **lst)
{
	int 	i;

	i = 0;
		while (argv[i])
	{
		if (push_back(lst, argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_opt		options;
	t_file		*lst;
	t_file		*tmp;
	int		n;

	n = 0;
	lst = NULL;
	tmp = NULL;
	if (argc < 1)
		return (-1);
	init_options(&options);
	n = get_path_index(argv, &options);
	if (!(argv[n]))
		read_args(".",".", &options);
	else
	{
		if (argc - n >= 2)
			options.argc = 1;
		if ((add_file_to_lst(argv + n, &lst)) < 0)
			return (-1);
		apply_right_sort(&lst, ".", &options);
		display_files(&lst, &options);
		if (lst->next)
			n = 1;
		while (lst)
		{
			if ((file_exist(lst->name) && is_dir(lst->name)) || (is_lnk(lst->name) && options.l != 1))
			{
				if (n == 1)
					display_dir_path(lst->name);
				if (read_args(lst->name, lst->name, &options) < 0)
					return (-1);
				if (lst->next)
					ft_putchar('\n');
			}
			lst = lst->next;
		}
		lst = tmp;
		free_lst(&lst);
	}
	// while (1);
	return (0);
}