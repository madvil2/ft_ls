/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:53:44 by pcollio-          #+#    #+#             */
/*   Updated: 2019/03/10 12:23:58 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H

# define FT_LS_H
# define	major(x)	((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define	minor(x)	((int32_t)((x) & 0xffffff))

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <time.h>
# include "../libft/libft.h"
# include <grp.h>
# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <libgen.h>

typedef struct	s_format {
	int total;
	char *file;
	char *chmod;
	char *user;
	char *group;
	char *date;
	char *name;
	int max;
	int max0;
	int	max1;
	int	max2;
	int max3;
	int	max4;
	int	max5;

	int width;
	int count_col;
	int max_row;

}				t_format;


typedef struct s_ls {
	int		l;
	int		r;
	int		l_r;
	int		a;
	int		t;

	char	**args;
	int		index;
	char	**files;
	int		index_f;
	char	**dir;
	int		index_d;
	int		max;
	int		rec;
	int		er;
	char	*path;
	int		format_max_1;
}				t_ls;

int			init_struct(t_ls *ls);
int			obj_type(const char* path);
void		put_usage(char a);
int			max_rows(int columns, int amount);
int			flags(char *args, t_ls *ls);
void		malloc_dir(int n, t_ls *ls);
void		malloc_files(int n, t_ls *ls);
int			get_time(char *f1, char *f2, t_ls *ls);
void		free_files(t_ls *ls);
void		free_dirs(t_ls *ls);
int			ft_strlen_two(char **a);
int			count_files(const char* path, t_ls *ls);
int			parcer(t_ls *ls, int argc, char **argv);
int			is_exist(const char* path);
int			get_attr(const char* path);
char		**sort_objs(char **obj, int n, t_ls *ls);
int			sort(t_ls *ls);
char		**push_dir_files_to_str(char *path, char **obj, t_ls *ls);
char		**dir_to_str(t_ls *ls);
void		push_dir_files(char *path, t_ls *ls);
int			push_dir(char *args, t_ls *ls);
int			push_files(char *args, t_ls *ls);
void		ls_dir(t_ls *ls);
void		ls_files(t_ls *ls);

int			format_rows(t_ls *ls);
int			format_rows_objs(char **objs, int n, t_ls *ls);

int			get_attr(const char* path);
off_t		get_size(char* path);
off_t		get_total_size(char** files, t_ls *ls);
char*		get_chmod(char *path);
int			vtorya_hernya(const char* path);
char*		get_user(const char* path);
char*		get_group(const char* path);
char		*get_last_time(char *path);
int			get_major(char *path);
int			get_minor(char *path);
char		*put_link(char *path);
int			l_format_rows_objs(char **objs, int n, t_ls *ls);
int			l_format_rows(t_ls *ls);
void		get_max_size(char** files, t_ls *ls);
int			ft_intlen(int n);


#endif
