/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 02:35:04 by dideryck          #+#    #+#             */
/*   Updated: 2017/11/30 02:52:22 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void *)&tab[i]);
		i++;
	}
	ft_memdel((void *)tab[i]);
	ft_memdel((void *)&tab);
}
