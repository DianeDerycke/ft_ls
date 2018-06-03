/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:07:18 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/03 23:20:28 by DERYCKE          ###   ########.fr       */
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
	char			*path;
	size_t		 	upd_time;
	struct s_file	*next;
	struct s_file	*prev;
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
	int 			d_size;
	int 			argc;
}					t_opt;

typedef int		(*opt)(t_dblist *lst);

//SRC
int				index_file(char **argv, t_opt *options, int argc);
void			read_args(char *path, t_opt *options);
void			recursive(t_file *subdir, char *path, t_opt *options);
char			*concat_time(char *str);
char			*concat_time_year(char *time_str);
char			*create_path(char *path, char *dirname);

//LST
t_file			*init_lst(void);
int				push_back(t_file **lst, char *str);
void			get_data_file(t_file **dir, char *path);
void			free_lst(t_file	**subdir);

//OPTIONS FUNCTIONS
void			apply_opt(t_file *lst, t_opt *options);
void    		get_right_size(char *path, t_opt *options);
void    		dis_mode(struct stat file_stat);
void    		dis_info(struct stat file_stat);
void    		dis_time(struct stat f_stat);


//DISPLAY
void			sort_display(t_file **lst, char *path, t_opt *options);
void			display_dir(t_file *lst, char *path, t_opt *options);
void			display_files(char **argv, t_opt *options);
void			display_reverse(t_file *lst, char *path, t_opt *options);
int				long_format(char *path, char *filename);
void			dis_link(char *path, char *filename);



//SORT FUNCTIONS
void			basic_sort_lst(t_file **lst);
void			reverse_sort(t_file **lst);
void			sort_args(char **argv, t_opt *options);
void			sort_time(t_file **lst);


//VERIFICATION
int 			file_exist(const char *path);
int				is_dir(const char *path);
int				is_lnk(const char *path);



//ERROR
void			error_option(char c);
void			error_no_file_or_dir(char *str);

#endif