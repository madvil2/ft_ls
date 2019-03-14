// #include "../includes/ft_ls.h"

char	*get_user(const char *path, t_ls *ls)
{
	struct stat		info;
	struct passwd	*pw;

	stat(path, &info);
	if ((pw = getpwuid(info.st_uid)))
	{
		if (ls->n)
			return (ft_itoa(pw->pw_uid));
		return ((char *)pw->pw_name);
	}
	return ("0");
}

char	*get_group(const char *path, t_ls *ls)
{
	struct stat		info;
	struct group	*gr;

	stat(path, &info);
	gr = getgrgid(info.st_gid);
	if (ls->n)
		return (ft_itoa(gr->gr_gid));
	return ((char *)gr->gr_name);
}

int main()
{
	printf("%u", get_group_id("/Users/pcollio-/Projects/ft_ls/author"));
}