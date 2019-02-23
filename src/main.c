#include "../includes/ft_ls.h"

void init_struct(t_ls *ls)
{
	ls->l = 0;
	ls->l_r = 0;
	ls->r = 0;
	ls->a = 0;
	ls->t = 0;
}

int get_args(int argc, char **argv, t_ls *ls)
{
	int index;
	int c;

	opterr = 0;
	index = 0;

	while ((c = getopt (argc, argv, "lRrat")) != -1)
		switch (c)
		{
			case 'l':
				ls->l = 1;
				break;
			case 'R':
				ls->l_r = 1;
				break;
			case 'r':
				ls->r = 1;
				break;
			case 'a':
				ls->a = 1;
				break;
			case 't':
				ls->t = 1;
				break;
			default:
				abort ();
		}
	// printf ("l = %d, R = %d, r = %d, a = %d, t = %d\n", ls->l, ls->l_r, ls->r, ls->a, ls->t);
	ls->str = (char **)malloc(sizeof(*ls->str) * (argc - index) + 1);
	int i = 0;
	for (index = optind; index < argc; index++)
	{
		ls->str[i] = ft_strdup(argv[index]);
		// printf ("ls->str: %s\n", ls->str[i++]);
		// printf ("argv: %s\n", argv[index]);
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
				if (get_time ((ls->str[i]), (ls->str[j])) > 0)
				{
					char *tmp = ls->str[i];
					ls->str[i] = ls->str[j];
					ls->str[j] = tmp;
				}
			}
			else
			{
				if (ft_strcmp((ls->str[i]), (ls->str[j])) > 0)
				{
					char *tmp = ls->str[i];
					ls->str[i] = ls->str[j];
					ls->str[j] = tmp;
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
	
	int count_col = width / ls->max;
	int min_lines = ls->index / count_col;
	int count_plus_lines = ls->index % count_col;
	/*транспонировать матрицу со стоками
		0 3 6
		1 4 7
		2 5    
	*/

	return (0);
}

int	ft_ls(t_ls *ls, int argc, char **argv)
{
	parcer(ls, argc, argv);
	sort(ls);
	format_rows(ls);

	return (0);
}

int	main (int argc, char **argv)
{
	t_ls	ls;

	init_struct(&ls);
	get_args(argc, argv, &ls);
	return (0);
}
