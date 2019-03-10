#include "../includes/ft_ls.h"

int	init_struct(t_ls *ls)
{
	ls->l = 0;
	ls->r = 0;
	ls->l_r = 0;
	ls->a = 0;
	ls->t = 0;
	ls->index = 0;
	ls->max = 0;
	ls->index_f = 0;
	ls->index_d = 0;
	ls->rec = 0;
	ls->max = 0;
	ls->er = 0;
	ls->path = 0;

	return (0);
}

int		obj_type(const char* path)
{
	struct stat path_stat;

	lstat(path, &path_stat);
	if ((path_stat.st_mode & S_IFMT) == S_IFREG)
		return (0); //regular file
	else if ((path_stat.st_mode & S_IFMT) == S_IFDIR)
		return(1); //directory
	else if ((path_stat.st_mode & S_IFMT) == S_IFCHR)
		return(2); //character device
	else if ((path_stat.st_mode & S_IFMT) == S_IFBLK)
		return(3); //block device
	else if ((path_stat.st_mode & S_IFMT) == S_IFIFO)
		return(4); //FIFO/pipe
	else if ((path_stat.st_mode & S_IFMT) == S_IFLNK)
		return(5); //symlink
	else if ((path_stat.st_mode & S_IFMT) == S_IFSOCK)
		return(7); //socket
	else
		return(-1); //unknown
}

void	put_usage(char a)
{
	printf("ls: illegal option -- %c\n", a);
	printf("usage: ls [-lrRat] [file ...]");
	exit(1);
}

int		max_rows(int columns, int amount)
{
	if (amount % columns)
		return ((amount / columns) + 1);
	return (amount / columns);
}

int	flags(char *args, t_ls *ls)
{
	int i = 0;
	if (args[i] == '-' && args[i + 1] > 32 && args[i + 1] < 127)
	{
		i++;
		while (args[i] > 32 && args[i] < 127)
		{
			if (args[i] == 'l')
				ls->l = 1;
			else if (args[i] == 'r')
				ls->r = 1;
			else if (args[i] == 'R')
				ls->l_r = 1;
			else if (args[i] == 'a')
				ls->a = 1;
			else if (args[i] == 't')
				ls->t = 1;
			else
				put_usage(args[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

void malloc_dir(int n, t_ls *ls)
{
	ls->dir = malloc(sizeof(char*) * (n + 1));
	ls->dir[n] = NULL;
	ls->index_d = 0;
}

void malloc_files(int n, t_ls *ls)
{
	ls->files = malloc(sizeof(char*) * (n + 1));
	ls->files[n] = NULL;
	ls->index_f = 0;
}

int get_time(char *f1, char *f2)
{
	struct stat s1;
	struct stat s2;
 
	lstat(f1, &s1);
	lstat(f2, &s2);
 
	if (s1.st_mtime < s2.st_mtime)
		return (1);
	return (0);
}

void free_files(t_ls *ls)
{
	int i = 0;
	while (i < ls->index_f)
	{
		free(ls->files[i]);
		i++;
	}
	free(ls->files);
}

void free_dirs(t_ls *ls)
{
	int i = 0;
	while (i < ls->index_d)
	{
		free(ls->dir[i]);
		i++;
	}
	free(ls->dir);
}

int ft_strlen_two(char **a)
{
	int i = 0;
	while (a[i])
		i++;
	return (i);
}

int		count_files(const char* path, t_ls *ls)
{
	DIR *d;
	int count;
	struct dirent *dir;
	count = 0;

	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.' || ls->a)
				count++; // printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
	return (count);
}

int		is_exist(const char* path)
{
	struct stat path_stat;
	return (stat(path, &path_stat) == 0);
}

int		get_attr(const char* path)
{
	acl_t acl = NULL;
	acl_entry_t dummy;
	ssize_t xattr = 0;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		return (1); // @
	else if (acl != NULL)
		return (2); // +
	else
		return (0);
}

char **dir_to_str(t_ls *ls)
{
	int i = 0;
	char **str;
	str = malloc(sizeof(char*) * (ls->index_d + 1));
	str[ls->index_d] = 0;
	while (i < ls->index_d)
	{
		str[i] = malloc(sizeof(char) * ft_strlen(ls->dir[i] + 1));
		int j = 0;
		while (j < (int)ft_strlen(ls->dir[i]))
		{
			str[i][j] = ls->dir[i][j];
			j++;
		}
		str[i][j] = '\0';
		i++;
	}
	free_dirs(ls);
	return (str);
}

char **push_dir_files_to_str(char *path, char **obj, t_ls *ls)
{
	DIR *d;
	int count;
	struct dirent *dir;
	count = 0;

	d = opendir(path);
	int i = 0;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.' || ls->a)
			{
				char *file = dir->d_name;
				int n = strlen(file);
				if (n > ls->max)
					ls->max = n;
				obj[i] = malloc(sizeof(char) * (n + 1));
				obj[i][n] = '\0';
				int j = 0;
				while (j < n)
				{
					obj[i][j] = file[j];
					j++;
				}
				i++;
			}
		}
		closedir(d);
	}
	return (obj);
}

void		push_dir_files(char *path, t_ls *ls)//, t_ls *ls
{
	DIR *d;
	int count;
	struct dirent *dir;
	count = 0;

	
	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
			if (dir->d_name[0] != '.')
				push_files(dir->d_name, ls);
		ls_files(ls);
		closedir(d);
	}
}

int push_files(char *args, t_ls *ls)
{
	int len = ft_strlen(args);

	if (len > ls->max)
		ls->max = len;
	ls->files[ls->index_f] = malloc(sizeof(char) * (len + 1));
	ls->files[ls->index_f][len] = '\0';
	int i = 0;
	while (i < len)
	{
		ls->files[ls->index_f][i] = args[i];
		i++;
	}
	(ls->index_f)++;
	return (0);
}

int push_dir(char *args, t_ls *ls)
{
	int len = ft_strlen(args);

	ls->dir[ls->index_d] = malloc(sizeof(char) * (len + 1));
	ls->dir[ls->index_d][len] = '\0';
	int i = 0;
	while (i < len)
	{
		ls->dir[ls->index_d][i] = args[i];
		i++;
	}
	(ls->index_d)++;
	return (0);
}

void ls_files(t_ls *ls)
{
	sort(ls);
	if (ls->l)
		l_format_rows(ls);
	else
		format_rows(ls);
}

void	ls_dir(t_ls *ls)
{
	int k = 0;
	int n = 0;
	while (k < ls->index_d)
	{
		n = count_files(ls->dir[k], ls);
		free_files(ls);
		malloc_files(n, ls);
		printf("\n%s:\n", ls->dir[k]);
		push_dir_files(ls->dir[k], ls);
		k++;
	}
}

int		ft_intlen(int n)
{
	return (ft_strlen(ft_itoa(n)));
}