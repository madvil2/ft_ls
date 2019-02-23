#include "../includes/ft_ls.h"

void init_struct(t_ls *ls)
{
	ls->l = 0;
	ls->l_r = 0;
	ls->r = 0;
	ls->a = 0;
	ls->t = 0;
}

int get_opt(int argc, char **argv, t_ls *ls)
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
	printf ("l = %d, R = %d, r = %d, a = %d, t = %d\n", ls->l, ls->l_r, ls->r, ls->a, ls->t);
	ls->str = (char **)malloc(sizeof(*ls->str) * (argc - index) + 1);

	for (index = optind; index < argc; index++)
	{
		*ls->str++ = ft_strdup(argv[index]);
		printf ("ls->str: %s\n", ls->str[index]);
		printf ("argv: %s\n", argv[index]);
	}

	return (0);
}

int	main (int argc, char **argv)
{
	t_ls	ls;

	init_struct(&ls);
	get_opt(argc, argv, &ls);
	return (0);
}