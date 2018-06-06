/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 21:44:39 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/06 22:22:13 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

char    *create_field(long long int max, char *str)
{
    char    *lnk;
    int     i;
    int     j;

    lnk = NULL;
    i = 0;
    j = 0;
    if (!(lnk = ft_memalloc(max + 2)))
        return (NULL);
    lnk[max + 1] = '\0';
    i = max + 1;
    j = ft_strlen(str);

    while (j >= 0)
    {
        lnk[i] = str[j];
        i--;
        j--;
    }
    while (i >= 0)
    {
        lnk[i] = ' ';
        i--;
    }
    return (lnk);
}

char		*create_field_usr_grp(unsigned short max, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_memalloc(max + 2)))
		return (NULL);
	ft_strcpy(tmp, str);
	i = ft_strlen(str);
	while (i < max)
	{
		tmp[i] = ' ';
		i++;
	}
	return (tmp);
}

char	*create_path(char *path, char *dirname)
{
	char	*newpath;
	char	*tmp;

	if ((!path || !dirname) || !(tmp = ft_strdup(path)))
		return (NULL);
	else if (!(newpath = ft_strjoin(tmp, "/")))
		return (NULL);
	else if (!(tmp = ft_strjoin(newpath, dirname)))
		return (NULL);
	return (tmp);
}