/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:47:48 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/22 13:10:01 by DERYCKE          ###   ########.fr       */
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