/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 22:46:22 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

t_stlist	*init_dblist(void)
{
	t_stlist 	*dblst;

	if (!(dblst = ft_memalloc(sizeof(t_stlist))))
		return (NULL);
	return (dblst);
}

void	add_file_to_lst(char *argv, t_stlist *dblist)
{
	if (!(file_exist(argv)))
		error_no_file_or_dir(argv);
	push_back(dblist, argv);
	basic_sort_lst(dblist);
}

int		main(int argc, char **argv)
{
	t_stlist	*dblist;
	t_opt		options;
	int		n;

	n = 0;
	if (!(dblist = init_dblist()) || argc < 1)
		return (-1);
	n = index_file(++argv, &options);
	if (!argv[n])
		add_file_to_lst(".", dblist);
	while (argv[n])
	{
		add_file_to_lst(argv[n], dblist);
		n++;
	}
	for_each_node(&options, dblist);			
	return (0);
}