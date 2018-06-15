/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/15 02:46:19 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt		options;
	int		n;

	n = 0;
	if (argc < 1)
		return (-1);
	init_options(&options);
	n = get_path_index(argv, &options);
	// printf("N VALUE %d\n", n);
	if (!(argv[n]))
		read_args(".", &options);
	else
	{
		sort_args(argv + n, &options);
		display_files(argv + n, &options);
		if (argc - n >= 2)
			options.argc = 1;
		while (argv[n])
		{
			if (file_exist(argv[n]) && (is_dir(argv[n]) || (is_lnk(argv[n]) && options.l != 1)))
				if (read_args(argv[n], &options) < 0)
					return (0);
			n++;
		}		
	}
	// while (1);
	return (0);
}