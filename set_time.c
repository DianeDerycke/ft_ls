/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:47:48 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/05 10:27:54 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

char	*concat_time(char *time_str)
{
	char	*tmp;

	tmp = NULL;
	if (!time_str)
		return (NULL);
	if (!(tmp = ft_strndup(time_str + 4, 12)))
		return (NULL);
	return (tmp);
}

char	*concat_time_year(char *time_str)
{
	char	*tmp;
	char	*time;

	time = NULL;
	tmp = NULL;
	if (!time_str)
		return (NULL);
	if (!(tmp = ft_strndup(time_str + 4, 7)) || !(time = ft_strjoin(tmp, time_str + 19)))
		return (NULL);
	time[ft_strlen(time) - 1] = '\0';
	return (time);
}