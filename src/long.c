#include "../includes/ft_ls.h"



off_t get_size(char* path)
{
	struct stat st;
	off_t size;

	stat(path, &st);
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
		stat(file, &st);
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

	chmod = malloc(sizeof(char) * 10 + 1);
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
		chmod[1] = (perm & S_IWUSR) ? 'w' : '-';
		chmod[2] = (perm & S_IXUSR) ? 'x' : '-';
		chmod[3] = (perm & S_IRGRP) ? 'r' : '-';
		chmod[4] = (perm & S_IWGRP) ? 'w' : '-';
		chmod[5] = (perm & S_IXGRP) ? 'x' : '-';
		chmod[6] = (perm & S_IROTH) ? 'r' : '-';
		chmod[7] = (perm & S_IWOTH) ? 'w' : '-';
		chmod[8] = (perm & S_IXOTH) ? 'x' : '-';
		if (get_attr(path) == 1)
			chmod[9] = '@';
		else if (get_attr(path) == 2)
			chmod[9] = '+';
		else
			chmod[9] = ' ';
		chmod[10] = '\0';
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

long long get_major(char *path)
{
	struct stat sp;
	long long m;

	stat(path, &sp);
	m = (long long)major(sp.st_rdev);
	return (m);
}

long long get_minor(char *path)
{
	struct stat sp;
	long long m;

	stat(path, &sp);
	m = (long long)minor(sp.st_rdev);
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