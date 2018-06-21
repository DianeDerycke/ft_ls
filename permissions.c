/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 00:19:00 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/22 00:59:32 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"


char    ext_attr(char *path)
{
    if (listxattr(path, NULL, 1, XATTR_NOFOLLOW) > 0)
        return ('@');
    return (' ');

}

void	permissions(mode_t mode, char *path)
{
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
   	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
    if (mode & S_ISUID)
       	ft_putchar(mode & S_IXUSR ? 's' : 'S');
    else
       	ft_putchar((mode & S_IXUSR) ? 'x' : '-');
   	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
   	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
    if (mode & S_ISGID)
       	ft_putchar(mode & S_IXGRP ? 's' : 'S');
    else
       	ft_putchar((mode & S_IXGRP) ? 'x' : '-');
   	ft_putchar((mode & S_IROTH) ? 'r' : '-');
   	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
    if (mode & S_ISVTX)
       	ft_putchar(mode & S_IXOTH ? 't' : 'T');
    else
       	ft_putchar((mode & S_IXOTH) ? 'x' : '-');
   	ft_putchar(ext_attr(path));
}

void    file_type(mode_t mode)
{
    if (S_ISBLK(mode))
        ft_putchar('b');
    else if (S_ISCHR(mode))
        ft_putchar('c');
    else if (S_ISDIR(mode))
        ft_putchar('d');
    else if (S_ISLNK(mode))
        ft_putchar('l');
    else if (S_ISSOCK(mode))
        ft_putchar('s');
    else if (S_ISFIFO(mode))
        ft_putchar('p');
    else
        ft_putchar('-');
}
