/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/22 14:27:57 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_dir(t_file *lst, char *path, t_opt *options)
{
	char	*tmp;
	char	*newpath;

	tmp = NULL;
	newpath = NULL;
	if (options->argc != 1 && lst)
		printf("\n%s:\n", path);
	else if (path && options->argc != 1)
		printf("\n%s:\n", path);
	else
		options->argc = 0;
	if (options->a != 1)
	{
		while (lst && lst->name[0] == '.')
			lst = lst->next;
	}
	if (options->l)
		while (lst)
		{
			tmp = ft_strdup(path);
			newpath = ft_strjoin(tmp, "/");
			tmp = ft_strjoin(newpath, lst->name);
			long_format(tmp, lst->name);
			free(tmp);
			lst = lst->next;
		}
	else
		while (lst)
		{
			printf("%s\n", lst->name);
			lst = lst->next;
		}
}//30 lignes

void	display_files(char **argv, t_opt *options)
{
	int		i;
	struct stat 	file_stat;

	i = 0;
	while (argv[i])
	{
		if (!(file_exist(argv[i])))
			error_no_file_or_dir(argv[i]);
		i++;
	}
	i = 0;
	while (argv[i])
	{
		if (file_exist(argv[i]) && !(is_dir(argv[i])))
		{
		    if (lstat(argv[i],&file_stat) < 0)
		        return ;
			if (options->l)
				long_format(argv[i], argv[i]);
			else if (!(S_ISLNK(file_stat.st_mode)))
				printf("%s\n", argv[i]);
		}
		i++;
	}
}