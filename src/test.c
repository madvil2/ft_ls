#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/xattr.h>
#include <sys/acl.h>

#include "../includes/ft_ls.h"



int main(int argc, char **argv, char **envp)
{




	printf("%s", put_link("LINK"));



































	// printf("%lld", get_major("/dev/ttyq1"));
	// printf("%lld", get_minor("/dev/ttyq1"));
	// printf("%s", get_last_time("src"));
	// printf("%s", get_group("00"));
	// printf("%d", vtorya_hernya("libft"));
	// printf("%s", get_chmod("Music"));

	// char **files;
	// files = malloc(sizeof(char*) *3);
	// files[2] = NULL;
	// files[0] = malloc(6);
	// files[0][0] = 't';
	// files[0][1] = 'e';
	// files[0][2] = 's';
	// files[0][3] = 't';
	// files[0][4] = '1';
	// files[0][5] = '\0';
	// files[1] = malloc(6);
	// files[1][0] = 't';
	// files[1][1] = 'e';
	// files[1][2] = 's';
	// files[1][3] = 't';
	// files[1][4] = '2';
	// files[1][5] = '\0';

	// printf("total = %lld\n", get_total_size(files));
	// printf("1 = %lld\n", get_size("test1"));
	// printf("2 = %lld\n", get_size("test2"));

	// printf("%d", get_time("00", "01"));


	// printf("%d", is_exist("00"));
	//printf("%d\n", get_attr("/Applications"));
	// printf("\n%d", obj_type("."));
//	printf("%d", c);




//printf("%s\n", dir->d_name);


/* 	DIR *a;
	struct dirent *entry;

	a = opendir("/Users/pcollio-/Projects/ft_ls/test");

	while ((entry = readdir(a)))
	{
		ft_printf("%lld - %s [%d] %d %d %lld\n",
			   entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen, entry->d_namlen, entry->d_seekoff);
	}
*/

//	struct stat f1;
//	struct stat f2;
//
//	stat("test", &f1);
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


	// printf("test = %ld\n\n", f1.st_ctime);
	// stat("libft", &f2);
	// printf("libf = %ld\n", f2.st_ctime);


//    printf ("columns %d\n", width);
// int amount = 10;
// int column = 3;

// 		if (amount % column)
// 			printf("%d \n",((amount / column) + 1));
// 		printf("%d \n",(amount / column));
}