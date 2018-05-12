/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:50:25 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 13:31:14 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	option_sort_time(t_stlist *dblist)
{
	(void)dblist;
	printf("%s\n", "SORT TIME" );
}

void	option_sort_reverse(t_stlist *dblist)
{
	(void)dblist;
	printf("%s\n", "SORT REVERSE");
}

void	option_l(t_stlist *dblist, t_opt *options)
{
	(void)dblist;
	(void)options;
	printf("%s\n", "LONG FORMAT");
}