/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:18:39 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/25 15:01:32 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	dis_link(char *path, char *filename)
{
	char	tmp[1024];
	int		buffsize;

	if ((buffsize = readlink(path, tmp, sizeof(tmp) - 1)) != -1)
		tmp[buffsize] = '\0';
	printf("%s%s%s\n", filename ? filename : path, " -> ", tmp);
}