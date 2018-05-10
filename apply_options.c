/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:04:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/10 15:13:01 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		apply_options(t_opt *options, t_file *lst, t_stlist *dblist)
{
	(void)options;
	t_file		*test;

	test = lst;
	printf("%s\n", "DISPLAY LST");
	while (test)
	{
		printf("%s\n", test->name);
		test = test->next;
	}
	printf("%s\n", "END DISPLAY");
	if (is_dir(lst->name) && ((ft_strcmp(lst->name, ".") != 0) || (ft_strcmp(lst->name, ".."))))
	{
		add_current_dir(dblist, lst->name);
		lst = lst->next;
	}
	if (!(lst->next))
		return (1);
	else
	{
		while (!(is_dir(lst->name)))
			lst = lst->next;
	}
	// apply_options(options, lst, dblist);
	return (0);
}