/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:47:48 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/28 15:27:49 by DERYCKE          ###   ########.fr       */
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
	char	*date;

	date = NULL;
	tmp = NULL;
	if (!time_str)
		return (NULL);
	if (!(tmp = ft_strndup(time_str + 4, 5)) || !(date = ft_strjoin(tmp, time_str + 18)))
		return (NULL);
	date[ft_strlen(date) - 1] = '\0';
	return (date);
}