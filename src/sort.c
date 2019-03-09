#include "ft_ls.h"

char **sort_objs(char **obj, int n, t_ls *ls)
{
	int i;
	int j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ls->t)
			{
				if (get_time ((obj[i]), (obj[j])) > 0)
				{
					char *tmp = obj[i];
					obj[i] = obj[j];
					obj[j] = tmp;
				}
			}
			else
			{
				if (ft_strcmp((obj[i]), (obj[j])) > 0)
				{
					char *tmp = obj[i];
					obj[i] = obj[j];
					obj[j] = tmp;
				}
			}
			j++;
		}
		i++;
	}
	if (ls->r)
	{
		i = 0;
		int med = n / 2;
		n--;
		while (i < med)
		{
			char *tmp = obj[i];
			obj[i] = obj[n - i];
			obj[n - i] = tmp;
			i++;
		}
	}
	return (obj);
}

int sort(t_ls *ls)
{
	int i;
	int j;

	i = 0;
	while (i < ls->index_f - 1)
	{
		j = i + 1;
		while (j < ls->index_f)
		{
			if (ls->t)
			{
				if (get_time ((ls->files[i]), (ls->files[j])) > 0)
				{
					char *tmp = ls->files[i];
					ls->files[i] = ls->files[j];
					ls->files[j] = tmp;
				}
			}
			else
			{
				if (ft_strcmp((ls->files[i]), (ls->files[j])) > 0)
				{
					char *tmp = ls->files[i];
					ls->files[i] = ls->files[j];
					ls->files[j] = tmp;
				}
			}
			j++;
		}
		i++;
	}
	if (ls->r)
	{
		i = 0;
		int med = ls->index_f / 2;
		while (i < med)
		{
			char *tmp = ls->files[i];
			ls->files[i] = ls->files[ls->index_f - 1 - i];
			ls->files[ls->index_f -1 - i] = tmp;
			i++;
		}
	}
	return (0);
}