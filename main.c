/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/25 18:11:26 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		treat_arg(t_file *lst, t_opt *options)
{
	t_file		*tmp;

	tmp = lst;
	if (!lst)
		return (EXIT_FAILURE);
	apply_right_sort(&lst, ".", options);
	while (lst)
	{
		if (is_stat_dir(lst->name) || (is_lnk(lst->name)))
		{
			if (options->nb_file)
				display_dir_path(lst->name);
			ft_read(lst->name, lst->name, options);
			if (lst->next)
				ft_putchar('\n');
		}
		lst = lst->next;
	}
	lst = tmp;
	free_lst(&tmp);
	
	return (EXIT_SUCCESS);
}

int				main(int argc, char **argv)
{
	t_opt		options;
	t_file		*lst;
	int			n;

	n = 0;
	lst = NULL;
	if (argc < 1)
		return (EXIT_FAILURE);
	init_options(&options);
	n = get_path_index(argv, &options);
	if (!(argv[n]))
		ft_read(".", ".", &options);
	else
	{
		add_file_to_lst(argv + n, &lst, &options);
		int a = treat_arg(lst, &options);
		while (1) ;
		return (a);
	}
	return (EXIT_SUCCESS);
}
