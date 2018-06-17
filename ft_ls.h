/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:07:18 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/16 23:34:07 by DERYCKE          ###   ########.fr       */
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

typedef struct			s_file
{
	char				*name;
	char				*path;
	struct timespec		upd_time;
	struct s_file		*next;
	struct s_file		*prev;
}						t_file;

typedef struct 			s_opt
{
	int					a;
	int					t;
	int					r;
	int					l;
	int 				tild;
	int					big_r;
	int					one;
	int 				argc;
	int 				d_size;
	long int 			max_size;
	unsigned short int 	max_lnk;
	unsigned short int	len_usr;
	unsigned short int	len_grp; 
}						t_opt;

//SRC
char					*create_path(char *path, char *dirname);
void					get_data_file(t_file **dir, char *path);
char					*define_path(char *path, char *name);


//PARSER
int						get_path_index(char **argv, t_opt *options);
int						read_args(char *filename, char *path, t_opt *options);

//LST
t_file					*init_lst(void);
int						push_back(t_file **lst, char *str);
void					free_lst(t_file	**subdir);
int						swap_content(t_file **ptr, t_file **next);
void 					delete_node(t_file *ptr);


//OPTIONS FUNCTIONS
void					recursive(t_file *subdir, char *path, t_opt *options);
char    				ext_attr(struct stat f_stat, char *path);
int						long_format(char *path, char *filename, t_opt *options);
int    					find_max_for_each(t_file *lst, t_opt *options);
void					sort_display(t_file **lst, char *path, t_opt *options); // A modifier
void					init_options(t_opt *options);
void					reset_options(t_opt *options);
char					*concat_time(char *str);
char					*concat_time_year(char *time_str);


//DISPLAY
void					display_content_dir(t_file *lst, t_opt *options);
void					display_files(t_file **lst, t_opt *options);
void					display_total_size(t_opt *options);
void					field_user(struct stat f_stat, t_opt *options);
void					field_grp(struct stat f_stat, t_opt *options);
void    				display_number(long long int max, char *str);
void        			display_usr_grp(unsigned short max, char *str);
void					display_dir_path(char *str);
void					dis_link(char *path, char *filename);
void    				dis_mode(struct stat file_stat, char *path);
void    				dis_info(struct stat file_stat, t_opt *options);
void    				dis_time(struct stat f_stat);

//SORT FUNCTIONS
void					basic_sort_lst(t_file **lst);
void					reverse_sort(t_file **lst);
void					sort_time(t_file **lst);

//VERIFICATION
int 					file_exist(const char *path);
int						is_dir(const char *path);
int						is_lnk(const char *path);


//ERROR
void					error_option(char c);
void					error_no_file_or_dir(char *str);
int						perm_denied(char *filename, char *path);

void					apply_right_sort(t_file **lst,char *path, t_opt *options);

#endif