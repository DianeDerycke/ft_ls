/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:09:22 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/11 23:24:22 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_stlist	*dblist;
	t_opt		options;
	t_file		*lst;
	int		n;

	lst = NULL;
	n = 0;
	dblist = init_dblist();
	if (argc > 1 && dblist)
	{
		n = index_file(++argv, &options);
		add_file_to_lst(argv + n, dblist);
		lst = dblist->first;
		// apply_options(&options,lst, dblist);
		while (lst)
		{
			printf("%s\n", lst->name);
			lst = lst->next;
		}
	}
	else if (argc == 1)
	{
		add_file_to_lst(++argv, dblist);
		lst = dblist->first;
		//afficher la liste chainée normalement sans les files cachés
	}
	return (0);
}