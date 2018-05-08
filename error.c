/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:15:14 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/08 19:19:59 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	error_option(char c)
{
	ft_putstr("ls: illegal options -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	exit(0);
}

void	error_no_file_or_dir(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory");
	exit(0);
}