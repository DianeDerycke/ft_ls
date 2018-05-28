/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/28 15:41:40 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt		options;
	int		n;

	n = 1;
	if (argc < 1)
		return (-1);
	n = index_file(&argv[n], &options, argc) + 1;
	if (!argv[n])
		read_args(".", &options);
	else
	{
		sort_args(argv + n);
		display_files(argv + n, &options);
		if (argc - n >= 2)
			options.argc = 1;
		while (argv[n])
		{
			if (file_exist(argv[n]) && (is_dir(argv[n]) || (is_lnk(argv[n]) && options.l != 1)))
				read_args(argv[n], &options);
			n++;
		}		
	}
	// while (1);
	return (0);
}