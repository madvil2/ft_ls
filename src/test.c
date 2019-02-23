#include "../includes/ft_ls.h"

int main()
{
/* 	DIR *a;
	struct dirent *entry;

	a = opendir("/Users/pcollio-/Projects/ft_ls/test");

	while ((entry = readdir(a)))
	{
		ft_printf("%lld - %s [%d] %d %d %lld\n",
			   entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen, entry->d_namlen, entry->d_seekoff);
	}
 */

	struct stat f1;
	struct stat f2;

	stat("/Users/pcollio-/Projects/ft_ls/test", &f1);
	// printf( (S_ISDIR(s.st_mode)) ? "d" : "-");
    // printf( (s.st_mode & S_IRUSR) ? "r" : "-");
    // printf( (s.st_mode & S_IWUSR) ? "w" : "-");
    // printf( (s.st_mode & S_IXUSR) ? "x" : "-");
    // printf( (s.st_mode & S_IRGRP) ? "r" : "-");
    // printf( (s.st_mode & S_IWGRP) ? "w" : "-");
    // printf( (s.st_mode & S_IXGRP) ? "x" : "-");
    // printf( (s.st_mode & S_IROTH) ? "r" : "-");
    // printf( (s.st_mode & S_IWOTH) ? "w" : "-");
    // printf( (s.st_mode & S_IXOTH) ? "x" : "-");
	// time_t lt;
	// lt = time(NULL);
	// printf("%s", ctime(&lt));


	// printf("%ld\n", f1.st_atime);
	// printf("%ld\n", f1.st_mtime);
	printf("test = %ld\n\n", f1.st_ctime);
	stat("/Users/pcollio-/Projects/ft_ls/libft", &f2);
	// printf("%ld\n", f2.st_atime);
	// printf("%ld\n", f2.st_mtime);
	printf("libf = %ld\n", f2.st_ctime);

	// system("tput cols");

	return 0;
}