/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/08 21:11:38 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_stlist	*dblist;
	t_file		*files;
	t_opt		options;
	int		n;

	n = 0;
	files = NULL;
	dblist = init_dblist();
	if (argc > 1 && dblist)
	{
		n = index_file(++argv, &options);
		add_file_to_lst(argv + n, dblist, &files);
		if (files)
		{
			printf("%s\n", files->name);
			// printf("%s\n", files->next->name);
		}
	}
	return (0);
}