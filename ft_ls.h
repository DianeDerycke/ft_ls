/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:07:18 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/21 21:11:16 by DERYCKE          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <grp.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>


typedef struct		s_file
{
	char			*name;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct s_stlist
{
	t_file		*first;
	t_file		*last;
}				t_stlist;

typedef struct 		s_opt
{
	int				a;
	int				t;
	int				r;
	int				l;
	int				big_r;
	int				one;
}					t_opt;

typedef int		(*opt)(t_dblist *lst);

//SRC
int				index_file(char **argv, t_opt *options);
void			read_args(char *path, t_opt *options);
void			recursive(t_file *subdir, char *path, t_opt *options);



//LST
t_file			*init_lst(void);
int				push_back(t_file **lst, char *str);
void			free_lst(t_file	**subdir);

//OPTIONS FUNCTIONS
void			apply_opt(t_file *lst, t_opt *options);
void			option_sort_time(t_file *lst);
void			option_sort_reverse(t_file *lst);
void			option_l(t_file *lst, t_opt *options);

//DISPLAY
void			display_dir(t_file *lst, char *path, t_opt *options);
void			display_files(char **argv, t_opt *options);
int				long_format(char *path, char *filename);


//SORT FUNCTIONS
void			basic_sort_lst(t_file **lst);
void			sort_args(char **argv);

//VERIFICATION
int 			file_exist(const char *path);
int				is_dir(const char *path);
int				usr_can_w(const char *path);


//ERROR
void			error_option(char c);
void			error_no_file_or_dir(char *str);

#endif