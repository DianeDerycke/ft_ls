/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:20:44 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/10 11:30:11 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		parsing(char *argv, t_opt *options)
{
	int		i;
	char	valid_opt[7] = "atrlR1";
	int		n;

	i = 0;
	n = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!(ft_strchr(valid_opt, argv[i])))
			error_option(argv[i]);
		if (argv[i] == 'a')
			options->a = 1;
		else if (argv[i] == 't')
			options->t = 1;
		else if (argv[i] == 'r')
			options->r = 1;
		else if (argv[i] == 'l')
			options->l = 1;
		else if (argv[i] == 'R')
			options->big_r = 1;
		else if (argv[i] =='1')
			options->one = 1;
		n++;
		i++;
	}
	return (1);
}

int		index_file(char **argv, t_opt *options)
{
	int		n;

	n = 0;
	while (argv[n] && argv[n][0] == '-')
	{
		parsing(argv[n], options);
		n++;
	}
	return (n);
}