/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:50:25 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/17 22:30:12 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	option_sort_time(t_file *lst)
{
	(void)lst;
	printf("%s\n", "SORT TIME" );
}

void	option_sort_reverse(t_file *lst)
{
	(void)lst;
	printf("%s\n", "SORT REVERSE");
}

void	option_l(t_file *lst, t_opt *options)
{
	(void)lst;
	(void)options;
	printf("%s\n", "LONG FORMAT");
}

void	apply_opt(t_file *lst, t_opt *options)
{
	if (options->t)
		option_sort_time(lst);
	if (options->r)
		option_sort_reverse(lst);
	if (options->l)
	{
		while (lst->next)
		{
			option_l(lst, options);
			lst = lst->next;
		}
	}
}
