#include "ft_ls.h"

int	format_rows(t_ls *ls)
{
	struct winsize w;
	int width;
	
	ioctl(0, TIOCGWINSZ, &w);
	width = w.ws_col;
	
	int max = ls->max + (8 - (ls->max % 8));
	//int max = ls->max + 1;
	int count_col = width / max;

	int max_row = max_rows(count_col, ls->index_f);

	int i = 0;
	int j;
	while (i < max_row)
	{
		int k = 0;
		while (k < count_col)
		{
			j = i + k * max_row;
			if (j < ls->index_f)
				printf("%-*s", max, ls->files[j]);
			k++;
		}
		printf("\n");
		i++;
	}

	return (0);
}

int	format_rows_objs(char **objs, int n, t_ls *ls)
{
	struct winsize w;
	int width;
	
	ioctl(0, TIOCGWINSZ, &w);
	width = w.ws_col;
	int max = ls->max + (8 - (ls->max % 8));
	int count_col = width / max;
	int max_row = max_rows(count_col, n);
	int i = 0;
	int j;
	while (i < max_row)
	{
		int k = 0;
		while (k < count_col)
		{
			j = i + k * max_row;
			if (j < n)
				printf("%-*s", max, objs[j]);
			k++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
