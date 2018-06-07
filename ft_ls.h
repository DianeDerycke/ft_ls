/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:07:18 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/07 13:38:11 by DERYCKE          ###   ########.fr       */
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
	size_t		 		upd_time;
	struct s_file		*next;
	struct s_file		*prev;
}						t_file;

typedef struct 			s_opt
{
	int					a;
	int					t;
	int					r;
	int					l;
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



//PARSER
int						index_file(char **argv, t_opt *options);
void					read_args(char *path, t_opt *options);

//LST
t_file					*init_lst(void);
int						push_back(t_file **lst, char *str);
void					free_lst(t_file	**subdir);
void					swap_content(t_file **ptr, t_file **next);


//OPTIONS FUNCTIONS
void					recursive(t_file *subdir, char *path, t_opt *options);
int						long_format(char *path, char *filename, t_opt *options);
int    					find_max_for_each(t_file *lst, t_opt *options);
void					sort_display(t_file **lst, char *path, t_opt *options); // A modifier
void					init_options(t_opt *options);
void					reset_options(t_opt *options);
char					*concat_time(char *str);
char					*concat_time_year(char *time_str);


//DISPLAY
void					display_dir(t_file *lst, char *path, t_opt *options);
void					display_files(char **argv, t_opt *options);
void					display_reverse(t_file *lst, char *path, t_opt *options);
void					display_total_size(t_opt *options);
void					field_user(struct stat f_stat, t_opt *options);
void					field_grp(struct stat f_stat, t_opt *options);
void    				display_number(long long int max, char *str);
void        			display_usr_grp(unsigned short max, char *str);
void					display_dir_path(char *str);
void					dis_link(char *path, char *filename);
void    				dis_mode(struct stat file_stat);
void    				dis_info(struct stat file_stat, t_opt *options);
void    				dis_time(struct stat f_stat);

//SORT FUNCTIONS
void					basic_sort_lst(t_file **lst);
void					reverse_sort(t_file **lst);
void					sort_args(char **argv, t_opt *options);
void					sort_time(t_file **lst);


//VERIFICATION
int 					file_exist(const char *path);
int						is_dir(const char *path);
int						is_lnk(const char *path);


//ERROR
void					error_option(char c);
void					error_no_file_or_dir(char *str);

#endif