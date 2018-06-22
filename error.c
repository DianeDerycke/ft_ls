/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:15:14 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/22 02:47:37 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	error_option(char c)
{

	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	error_no_file_or_dir(char *str)
{
	extern int		errno;

	if (errno)
	{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": No such file or directory", 2);		
	}
}

void	display_error_files(t_file **lst, t_opt *options)
{
	t_file	*files;

	files = *lst;
	if (!files)
		return ;
	options->nb_file++;
	lexico_sort(&files);
	while (files)
	{
		error_no_file_or_dir(files->name);
		files = files->next;
	}
	*lst = files;
	free_lst(lst);
}

int		perm_denied(char *filename)
{
	extern int 		errno;

	if (errno)
	{
		ft_putstr_fd("\nls: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": Permissions denied", 2);		
	}
	return (EXIT_FAILURE);
}

void	malloc_error(void)
{
	extern int 		errno;

	if (errno)
		ft_putstr_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
}