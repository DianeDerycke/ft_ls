/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:18:08 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 17:51:09 by DERYCKE          ###   ########.fr       */
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

void	add_file_to_lst(char **argv, t_stlist *dblist)
{
	int				i;

	i = 0;
	if (!argv[i])
		push_back(dblist, ".");
	else
	{
		while (argv[i])
		{
			if (!(file_exist(argv[i])))
				error_no_file_or_dir(argv[i]);
			push_back(dblist, argv[i]);
			i++;
		}		
	}
	basic_sort_lst(dblist);
}