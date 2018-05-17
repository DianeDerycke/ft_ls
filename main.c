/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/17 22:30:10 by DERYCKE          ###   ########.fr       */
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
	n = index_file(&argv[n], &options) + 1;
	if (!argv[n])
		read_args(".", &options);
	else
	{
		// trier argument avec argv + n
		while (argv[n])
		{
			if (!(file_exist(argv[n])))
				error_no_file_or_dir(argv[n]);
			read_args(argv[n], &options);
			n++;
		}		
	}
	return (0);
}