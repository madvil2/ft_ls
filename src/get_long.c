/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 10:01:54 by drestles          #+#    #+#             */
/*   Updated: 2019/03/10 12:37:28 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

off_t get_size(char* path)
{
	struct stat st;
	off_t size;

	lstat(path, &st);
	size = st.st_size;
	return (size);
}

off_t get_total_size(char** files, t_ls *ls)
{
	off_t total;
	struct stat st;
	int i;
	char *file;

	i = 0;
	total = 0;
	while (files[i] != NULL)
	{
		file = ft_strjoin(ls->path, files[i]);
		//здесь нужно фришнуть
		lstat(file, &st);
		total += st.st_blocks;
		i++;
	}
	return (total);
}

char* get_chmod(char *path)
{
	struct stat st;
	mode_t perm;
	char *chmod;

	chmod = malloc(sizeof(char) * 11 + 1);
	if(lstat(path, &st) == 0)
	{
		perm = st.st_mode;
		if ((st.st_mode & S_IFMT) == S_IFREG)
			chmod[0] = '-';
		else if ((st.st_mode & S_IFMT) == S_IFDIR)
			chmod[0] = 'd';
		else if ((st.st_mode & S_IFMT) == S_IFCHR)
			chmod[0] = 'c';
		else if ((st.st_mode & S_IFMT) == S_IFBLK)
			chmod[0] = 'b';
		else if ((st.st_mode & S_IFMT) == S_IFLNK)
			chmod[0] = 'l';
		chmod[1] = (perm & S_IRUSR) ? 'r' : '-';
		chmod[2] = (perm & S_IWUSR) ? 'w' : '-';
		chmod[3] = (perm & S_IXUSR) ? 'x' : '-';
		chmod[4] = (perm & S_IRGRP) ? 'r' : '-';
		chmod[5] = (perm & S_IWGRP) ? 'w' : '-';
		chmod[6] = (perm & S_IXGRP) ? 'x' : '-';
		chmod[7] = (perm & S_IROTH) ? 'r' : '-';
		chmod[8] = (perm & S_IWOTH) ? 'w' : '-';
		chmod[9] = (perm & S_IXOTH) ? 'x' : '-';
		if (get_attr(path) == 1)
			chmod[10] = '@';
		else if (get_attr(path) == 2)
			chmod[10] = '+';
		else
			chmod[10] = ' ';
		chmod[11] = '\0';
	}
	return (chmod);
}

int		vtorya_hernya(const char* path)
{
	DIR *d;
	int count;
	struct dirent *dir;
	struct stat st;

	count = 0;
	lstat(path, &st);
	if ((st.st_mode & S_IFMT) == S_IFDIR)
	{
		d = opendir(path);
		while ((dir = readdir(d)) != NULL)
				count++;
		closedir(d);
	}
	else
		count = 1;
	return (count);
}

char* get_user(const char* path)
{
	struct stat info;
	struct passwd *pw;

	stat(path, &info);
	pw = getpwuid(info.st_uid);
	return((char *)pw->pw_name);
}

char* get_group(const char* path)
{
	struct stat info;
	struct group *gr;

	stat(path, &info);
	gr = getgrgid(info.st_gid);
	return((char *)gr->gr_name);
}

char *get_last_time(char *path)
{
	struct stat st;
	char *raw_data;
	char *data;
	int i;
	int j;

	j = 0;
	i = 4;
	stat(path, &st);
	raw_data = ctime(&st.st_mtime);
	data = (char *)malloc(sizeof(char) * 16);
	while (i != 16)
		data[j++] = raw_data[i++];
	data[j] = '\0';
	return (data);
}

int get_major(char *path)
{
	struct stat sp;
	int		m = 0;

	stat(path, &sp);
	m = major(sp.st_rdev);
	return (m);
}

int get_minor(char *path)
{
	struct stat sp;
	int m = 0;

	stat(path, &sp);
	m = minor(sp.st_rdev);
	return (m);
}

char *put_link(char *path)
{
	struct stat st;
	// char *name;
	char *res;

	lstat(path, &st);
	if ((st.st_mode & S_IFMT) == S_IFLNK)
	{
		res = ft_strdup(basename(path));
		res = ft_strjoin(res, " -> ");
		res = ft_strjoin(res, basename(realpath(path, NULL)));
		return (res);
	}
	return (basename(path));
}

int			get_attr(const char *path)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		return (1);
	else if (acl != NULL)
		return (2);
	else
		return (0);
}

int			get_time(char *f1, char *f2, t_ls *ls)
{
	struct stat	s1;
	struct stat	s2;
	char		*file1;
	char		*file2;

	file1 = ft_strjoin(ls->path, f1);
	file2 = ft_strjoin(ls->path, f2);
	lstat(file1, &s1);
	lstat(file2, &s2);
	if (s1.st_mtime < s2.st_mtime)
		return (1);
	if (s1.st_mtime == s2.st_mtime)
		return (0);
	return (-1);
}