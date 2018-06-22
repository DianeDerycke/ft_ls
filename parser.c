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

static void		valid_option(char c, t_opt *options	)
{
	if (c == 'a')
		options->a = 1;
	else if (c == 'o')
		options->o = 1;
	else if (c == 'g')
		options->g = 1;
	else if (c == 't')
		options->t = 1;
	else if (c == 'r')
		options->r = 1;
	else if (c == 'l')
		options->l = 1;
	else if (c == 'R')
		options->big_r = 1;
	else if (c =='1' && (options->l == 1 || options->o || options->g))
		options->one = 1;
	else if (c == '-')
		options->tild = 1;
}

static void		parsing(char *argv, t_opt *options)
{
	int		i;
	char	valid_opt[10] = "aogtrlR1-";

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!(ft_strchr(valid_opt, argv[i])) || 
			(argv[i] == '-' && ft_strlen(argv) > 2))
			error_option(argv[i]);
		else
			valid_option(argv[i], options);
		i++;
	}
}

int		get_path_index(char **argv, t_opt *options)
{
	int		n;

	n = 0;
	argv++;
	while (argv[n] && argv[n][0] == '-' && 
		ft_strlen(argv[n]) > 1)
	{
		parsing(argv[n], options);
		n++;
		if (options->tild == 1)
			break ;
	}
	return (n + 1);
}