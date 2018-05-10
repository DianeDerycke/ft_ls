/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:07:18 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/05/10 14:58:40 by DERYCKE          ###   ########.fr       */
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
void			add_file_to_lst(char **argv, t_stlist *dblist);
void			add_current_dir(t_stlist *dblist, const char *path);


//LST
void			new_elem(t_file **lst);
t_stlist		*init_dblist(void);
void			push_back(t_stlist *dblist, char *str);



//OPTIONS FUNCTIONS
int				apply_options(t_opt *options, t_file *lst, t_stlist *dblist)	;


//DISPLAY

//SORT FUNCTIONS
void			basic_sort_lst(t_stlist *lst);

//VERIFICATION
int 			file_exist(const char *path);
int				is_dir(const char *path);


//ERROR
void			error_option(char c);
void			error_no_file_or_dir(char *str);

#endif
