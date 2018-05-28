/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/28 15:54:05 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	sort_display(t_file **lst, char *path, t_opt *options)
{
	// if (options->t)
	// 	sort_time(lst);
	// else
	// 	basic_sort_lst(lst);
	// if (options->r)
	// 	display_reverse(*lst, path, options);
	// else
		display_dir(*lst, path, options);
}

void	display_reverse(t_file *lst, char *path, t_opt *options)
{
	(void)lst;
	(void)path;
	(void)options;
}

void	display_dir(t_file *lst, char *path, t_opt *options)
{
	char	*tmp;

	tmp = NULL;
	if ((is_dir(path) || is_lnk(path)) && options->argc == 1)
		printf("\n%s:\n", path);
	if (options->l)
	{
		get_right_size(path, options);
		while (lst)
		{
			tmp = create_path(path, lst->name);
			long_format(tmp, lst->name);
			free(tmp);
			lst = lst->next;
		}
	}
	else
		while (lst)
		{
			printf("%s\n", lst->name);
			lst = lst->next;
		}
}

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