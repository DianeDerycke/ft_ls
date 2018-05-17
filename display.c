/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/17 15:22:27 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_dir(t_file *lst, char *path, t_opt *options)
{
	(void)path;

	printf("%s:\n", path);
	while (lst->next && options->a == 0 && lst->name[0] == '.')
		lst = lst->next;
	while (lst)
	{
		printf("%s\n", lst->name);
		lst = lst->next;
	}
	printf("\n\n");
}