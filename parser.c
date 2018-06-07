	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:20:44 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/24 16:51:04 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		valid_option(char c, t_opt *options)
{
	if (c == 'a')
		options->a = 1;
	else if (c == 't')
		options->t = 1;
	else if (c == 'r')
		options->r = 1;
	else if (c == 'l')
		options->l = 1;
	else if (c == 'R')
		options->big_r = 1;
	else if (c =='1')
		options->one = 1;
}

static void		parsing(char *argv, t_opt *options)
{
	int		i;
	char	valid_opt[7] = "atrlR1";

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!(ft_strchr(valid_opt, argv[i])))
			error_option(argv[i]);
		else
			valid_option(argv[i], options);
		i++;
	}
}

int		index_file(char **argv, t_opt *options, int argc)
{
	int		n;

	n = 0;
	(void)argc;
	while (argv[n] && argv[n][0] == '-')
	{
		parsing(argv[n], options);
		n++;
	}
	return (n);
}