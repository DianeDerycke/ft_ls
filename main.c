/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/17 19:21:10 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int				main(int argc, char **argv)
{
	t_opt		options;
	t_file		*lst;
	int		n;

	n = 0;
	lst = NULL;
	if (argc < 1)
		return (-1);
	init_options(&options);
	n = get_path_index(argv, &options);
	if (!(argv[n]))
		read_args(".",".", &options);
	else
	{
		add_file_to_lst(argv + n, &lst);
		apply_right_sort(&lst, ".", &options);
		display_files(&lst, &options);
		return (treat_arg(lst, argv, n, &options));
	}
	return (0);
}