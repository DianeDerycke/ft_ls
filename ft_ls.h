/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:07:18 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/12 21:23:45 by DERYCKE          ###   ########.fr       */
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
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>


typedef struct		s_file
{
	char			*name;
	char			*path;
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
void			add_file_to_lst(char *argv, t_stlist *dblist);
void			for_each_node(t_opt *options, t_stlist *dblist);
void			read_directory(char *path, t_opt *options);
// void			recursive(char *path, t_opt *options);




//LST
t_stlist		*init_dblist(void);
void			push_back(t_stlist *dblist, char *str);

//OPTIONS FUNCTIONS
void			apply_opt(t_stlist	*dblist, t_opt *options);
void			option_sort_time(t_stlist *dblist);
void			option_sort_reverse(t_stlist *dblist);
void			option_l(t_stlist *dblist, t_opt *options);

//DISPLAY
// void			apply_right_display(t_stlist *dblist, char *path, t_opt *options);
void			display_dir(t_stlist *dblist, char *path, t_opt *options);

//SORT FUNCTIONS
void			basic_sort_lst(t_stlist *lst);

//VERIFICATION
int 			file_exist(const char *path);
int				is_dir(const char *path);

//ERROR
void			error_option(char c);
void			error_no_file_or_dir(char *str);

#endif