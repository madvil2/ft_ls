#include "ft_ls.h"

int	init_struct(t_ls *ls)
{
	ls->l = 0;
	ls->r = 0;
	ls->l_r = 0;
	ls->a = 0;
	ls->t = 0;
	ls->index = 0;
	ls->max = 0;

	return (0);
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

int		get_args(int argc, char **argv, t_ls *ls)
{
	int index;
	int c;
	int len;

	opterr = 0;
	index = 0;
	while ((c = getopt (argc, argv, "lRrat")) != -1)
	{
		if (c == 'l')
			ls->l = 1;
		else if (c == 'R')
			ls->l_r = 1;
		else if (c == 'r')
			ls->r = 1;
		else if (c == 'a')
			ls->a = 1;
		else if (c == 't')
			ls->t = 1;
		else
			put_usage(*argv[ls->index]);
	}
	//printf ("l = %d, R = %d, r = %d, a = %d, t = %d\n", ls->l, ls->l_r, ls->r, ls->a, ls->t);
	ls->args = (char **)malloc(sizeof(*ls->args) * (argc - index) + 1);
	index = optind;
	while (index < argc)
	{
		ls->args[ls->index] = ft_strdup(argv[index]);
		//printf ("ls->str: %s\n", ls->args[(ls->index)]);
		len = (int)ft_strlen(ls->args[ls->index]);
		if (len > ls->max)
			ls->max = len;
		(ls->index)++;
		index++;
	}
	return (0);
}

int get_time(char *f1, char *f2)
{
	struct stat s1;
	struct stat s2;
 
	stat(f1, &s1);
	stat(f2, &s2);
 
	if (s1.st_ctime > s2.st_ctime)
		return (1);
	return (0);
}

int sort(t_ls *ls)
{
	int i;
	int j;

	i = 0;
	while (i < ls->index - 1)
	{
		j = i + 1;
		while (j < ls->index)
		{
			if (ls->t)
			{
				if (get_time ((ls->args[i]), (ls->args[j])) > 0)
				{
					char *tmp = ls->args[i];
					ls->args[i] = ls->args[j];
					ls->args[j] = tmp;
				}
			}
			else
			{
				if (ft_strcmp((ls->args[i]), (ls->args[j])) > 0)
				{
					char *tmp = ls->args[i];
					ls->args[i] = ls->args[j];
					ls->args[j] = tmp;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	format_rows(t_ls *ls)
{
	struct winsize w;
	int width;
	
	ioctl(0, TIOCGWINSZ, &w);
	width = w.ws_col;

	int max = ls->max;
	max = ls->max + (8 - (ls->max % 8));
	int count_col = width / max;

	int max_row = max_rows(count_col, ls->index);

	int i = 0;
	int j;
	while (i < max_row)
	{
		int k = 0;
		while (k < count_col)
		{
			j = i + k * max_row;
			if (j < ls->index)
				printf("%-*s", max, ls->args[j]);
			k++;
		}
		printf("\n");
		i++;
	}
	return (0);
}


int	ft_ls(t_ls *ls, int argc, char **argv)
{
	get_args(argc, argv, ls);
	sort(ls);
	format_rows(ls);

	return (0);
}

int main(int argc, char **argv)
{
	t_ls ls;
	init_struct(&ls);
	ft_ls(&ls, argc, argv);

	return (0);
}
