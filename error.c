/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:15:14 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/25 17:52:23 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_option(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls ", 2);
	ft_putendl_fd("[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]", 2);
	exit(EXIT_FAILURE);
}

 void	error_no_file_or_dir(char *str)
 {
 	extern int		errno;
 
 	if (errno)
 	{
 		ft_putstr_fd("ls: ", 2);
 		ft_putstr_fd(*str ? str : "fts_open", 2);
 		ft_putendl_fd(": No such file or directory", 2);		
 	}
 	if (!(*str))
 		exit(EXIT_FAILURE);
 }

void	display_error_files(t_file **lst, t_opt *options)
{
	t_file			*files;

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
	free_lst(lst);
}

int		perm_denied(char *filename)
{
	extern int		errno;

	if (errno)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": Permissions denied\n", 2);
	}
	return (EXIT_FAILURE);
}

void	malloc_error(void)
{
	extern int		errno;

	if (errno)
		ft_putstr_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
}
