/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:54:55 by dideryck          #+#    #+#             */
/*   Updated: 2017/11/30 00:49:40 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;

	str = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
