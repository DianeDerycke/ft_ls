/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:08:24 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/22 13:08:42 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"


int		long_format(char *path, char *filename)
{
    struct stat 	file_stat;
    struct passwd	*user_passwd;
    struct group   *grp_passwd;
    char			tmp[1024];
    char			*time_concat;
    int				buffsize;

    buffsize = 0;
    if (lstat(path,&file_stat) < 0)    
        return (1);
 	user_passwd = getpwuid(file_stat.st_uid);
 	grp_passwd = getgrgid(file_stat.st_gid);
 	time_concat = concat_time(ctime(&file_stat.st_mtime));
    printf( (S_ISDIR(file_stat.st_mode)) ? "d" : "-");
    printf( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("   %d   ",file_stat.st_nlink);
    if (user_passwd)
    	printf("%s   ", user_passwd->pw_name);
    else
    	printf("%u   ", file_stat.st_uid);
    if (grp_passwd)
    	printf("%s   ", grp_passwd->gr_name);
    else if (file_stat.st_gid)
    	printf("%u   ", file_stat.st_gid);
    printf("%lld   ",file_stat.st_size);
    if (time_concat)
    {
    	printf("%s   ", time_concat);
    	free(time_concat);
    }
    if (S_ISLNK(file_stat.st_mode))
    {
    	if ((buffsize = readlink(path, tmp, sizeof(tmp) - 1)) != -1)
	    		tmp[buffsize] = '\0';
    	printf("%s%s%s\n", filename, " -> ", tmp);
    }
    else
    	printf("%s\n", filename);

    return (0);
}