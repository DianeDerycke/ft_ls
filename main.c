/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 16:50:57 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_stlist	*dblist;
	t_opt		options;
	int		n;

	n = 0;
	dblist = init_dblist();
	if (argc >= 1 && dblist)
	{
		n = index_file(++argv, &options);
		add_file_to_lst(argv + n, dblist);
		for_each_node(&options, dblist);
	}
	// else if (argc == 1)
	// {
	// 	add_file_to_lst(++argv, dblist);
	// 	lst = dblist->first;
		//afficher la liste chainée normalement sans les files cachés
	// }
	return (0);
}