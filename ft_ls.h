/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DERYCKE <DERYCKE@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:07:18 by DERYCKE           #+#    #+#             */
/*   Updated: 2018/06/30 12:16:37 by dideryck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/acl.h>
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

typedef struct			s_opt
{
	int					a;
	int					o;
	int					g;
	int					t;
	int					r;
	int					l;
	int					tild;
	int					big_r;
	int					big_g;
	int					one;
	int					d_size;
	long int			max_sizef;
	unsigned short int	max_lnk;
	unsigned short int	len_usr;
	unsigned short int	len_grp;
	int					nb_file;
}						t_opt;

int						get_path_index(char **argv, t_opt *options);
int						ft_read(char *filename, char *path, t_opt *options);

int						swap_content(t_file **ptr, t_file **next);
t_file					*init_lst(void);
void					push_back(t_file **lst, char *str);
void					free_lst(t_file	**lst);
void					add_file_to_lst(char **argv, t_file **lst,
						t_opt *options);

void					recursive(t_file *subdir, char *path, t_opt *options);
int						long_format(char *path, char *filename, t_opt *options);
int						find_max_for_each(t_file *lst, t_opt *options);
void					init_options(t_opt *options);
void					reset_options(t_opt *options);
char					*concat_time(char *str);
char					*concat_time_year(char *time_str);

void					display_dir_path(char *str);
void					display_content_dir(t_file *lst, t_opt *options);
void					display_files(t_file *lst, t_file **files,
						t_opt *options);
void					display_link(char *path, char *filename, int big_g);

void					display_total_size(int total_size);
void					file_type(mode_t mode);
void					permissions(mode_t mode, char *path);
char					ext_attr(char *path);
void					display_info(struct stat file_stat, t_opt *options);
void					field_user(struct stat f_stat, t_opt *options);
void					field_grp(struct stat f_stat, t_opt *options);
void					display_usr_grp(unsigned short max, char *str);
void					major_minor_dev_number(dev_t dev_id);
void					display_number(long long int max, char *str);
void					display_time(struct stat f_stat);

void					lexico_sort(t_file **lst);
void					reverse_sort(t_file **lst);
void					sort_time(t_file **lst);
void					apply_right_sort(t_file **lst, char *path,
						t_opt *options);

int						file_exist(const char *path);
int						is_stat_dir(const char *path);
int						is_lstat_dir(const char *path);
int						is_lnk(const char *path);

void					error_option(char c);
void					error_no_file_or_dir(char *str);
void					display_error_files(t_file **lst, t_opt *options);
int						perm_denied(char *filename);
void					malloc_error(void);

void					get_data_file(t_file **dir, char *path);
char					*create_path(char *path, char *dirname);
void					insert_color(char *path, int big_g);

#endif
