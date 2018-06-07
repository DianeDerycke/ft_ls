/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:21:45 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/07 12:51:01 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	reset_options(t_opt *options)
{
	options->d_size = 0;
	options->max_size = 0;
	options->max_lnk = 0;
	options->len_usr = 0;
	options->len_grp = 0;
}

void	init_options(t_opt *options)
{
	options->a = 0;
	options->t = 0;
	options->r = 0;
	options->l = 0;
	options->big_r = 0;
	options->one = 0;
	options->d_size = 0;
	options->argc = 0;
	options->max_lnk = 0;
	options->max_size = 0;
	options->len_usr = 0;
	options->len_grp = 0;
}

t_file		*init_lst(void)
{
	t_file	*new;

	if (!(new = ft_memalloc(sizeof(t_file))))
		return (NULL);
	return (new);
}