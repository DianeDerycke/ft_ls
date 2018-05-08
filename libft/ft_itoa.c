/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dideryck <dideryck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:59:35 by dideryck          #+#    #+#             */
/*   Updated: 2017/11/30 00:49:04 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size_str(int nb)
{
	int		i;
	int		neg;

	neg = (nb < 0 ? 2 : 1);
	i = 0;
	if (nb == 0)
		return (2);
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i + neg);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		tmp;
	int		i;
	int		size_str;

	tmp = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_size_str(n))))
		return (NULL);
	if (n == 0)
		return (ft_memcpy(str, "0", 2));
	i = ft_size_str(n) - 1;
	size_str = ft_size_str(n) - 1;
	if (n < 0)
	{
		n = (unsigned int)(-n);
		str[0] = '-';
	}
	while (n)
	{
		tmp = (unsigned int)n % 10;
		str[--i] = tmp + '0';
		n = (unsigned int)n / 10;
	}
	str[size_str] = '\0';
	return (str);
}
