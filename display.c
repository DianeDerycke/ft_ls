/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:37:10 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/21 22:20:39 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	display_dir(t_file *lst, char *path, t_opt *options)
{
	printf("\n\n%s:\n", path);
	char	*tmp;
	char	*newpath;

	tmp = NULL;
	newpath = NULL;
	if (options->a != 1)
	{
		while (lst && lst->name[0] == '.')
			lst = lst->next;
	}
	if (options->l)
		while (lst)
		{
			tmp = ft_strdup(path);
			newpath = ft_strjoin(tmp, "/");
			tmp = ft_strjoin(newpath, lst->name);
			long_format(tmp, lst->name);
			free(tmp);
			lst = lst->next;
		}
	else
		while (lst)
		{
			printf("%s\n", lst->name);
			lst = lst->next;
		}
}

void	display_files(char **argv, t_opt *options)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!(is_dir(argv[i])) && file_exist(argv[i]))
		{
			if (options->l)
				long_format(argv[i], argv[i]);
			else
				printf("%s\n", argv[i]);
		}
		else if (!(file_exist(argv[i])))
			error_no_file_or_dir(argv[i]);
		i++;
	}
}

int		long_format(char *path, char *filename)
{
    struct stat 	file_stat;
    struct passwd	*user_passwd;
    struct group   *grp_passwd;
    char			tmp[1024];
    int				buffsize;

    buffsize = 0;
    if (lstat(path,&file_stat) < 0)    
        return (1);
 	user_passwd = getpwuid(file_stat.st_uid);
 	grp_passwd = getgrgid(file_stat.st_gid);
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
    printf("%s   ", ctime(&file_stat.st_mtime));

    //month + day of month last modified + hour file last modifie
    // + minue file last modified
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