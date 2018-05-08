/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 21:21:33 by dderycke          #+#    #+#             */
/*   Updated: 2017/11/30 00:49:48 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t					i;
	size_t					j;
	const unsigned char		*s1;
	const unsigned char		*s2;

	i = 0;
	j = i - 1;
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((!s1[i] || !s2[i]) && i < n)
		return (s1[i] - s2[i]);
	return (0);
}
