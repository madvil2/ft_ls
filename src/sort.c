/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 10:01:43 by drestles          #+#    #+#             */
/*   Updated: 2019/03/10 10:54:05 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* void	sort_time_objs(char **a, char **b)
{
	if (get_time(*a, *b) >= 0)
	{
		char *tmp = *a;
		*a = *b;
		*b = tmp;
	}
	if (get_time(*a, *b) == 0)
	{
		if (ft_strcmp(*a, *b) > 0)
		{
			char *tmp = *a;
			*a = *b;
			*b = tmp;
		}
	}
}
 */

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
				if (get_time(obj[i], obj[j], ls) >= 0)
				{
					char *tmp = obj[i];
					obj[i] = obj[j];
					obj[j] = tmp;
				}
				if (get_time(obj[i], obj[j], ls) == 0)
				{
					if (ft_strcmp(obj[i], obj[j]) > 0)
					{
						char *tmp = obj[i];
						obj[i] = obj[j];
						obj[j] = tmp;
					}
				}
			}
				//sort_time_objs(&(obj[i]), &(obj[j]));
			else
			{
				if (ft_strcmp(obj[i], obj[j]) > 0)
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

void sort_time(t_ls *ls, int i, int j)
{
	char *tmp;
	if (get_time ((ls->files[i]), (ls->files[j]), ls) >= 0)
	{
		tmp = ls->files[i];
		ls->files[i] = ls->files[j];
		ls->files[j] = tmp;
	}
	if (get_time ((ls->files[i]), (ls->files[j]), ls) == 0)
	{
		if (ft_strcmp((ls->files[i]), (ls->files[j])) > 0)
		{
			tmp = ls->files[i];
			ls->files[i] = ls->files[j];
			ls->files[j] = tmp;
		}
	}	
}

void	sort_ascii(t_ls *ls, int i, int j)
{
	char *tmp;
	if (ft_strcmp((ls->files[i]), (ls->files[j])) > 0)
	{
		tmp = ls->files[i];
		ls->files[i] = ls->files[j];
		ls->files[j] = tmp;
	}
}

void	sort_rec(t_ls *ls)
{
	int med;
	int i;
	char *tmp;

	i = 0;
	med = ls->index_f / 2;
	while (i < med)
	{
		tmp = ls->files[i];
		ls->files[i] = ls->files[ls->index_f - 1 - i];
		ls->files[ls->index_f - 1 - i] = tmp;
		i++;
	}
}

int		sort(t_ls *ls)
{
	int		i;
	int		j;

	i = 0;
	while (i < ls->index_f - 1)
	{
		j = i + 1;
		while (j < ls->index_f)
		{
			if (ls->t)
				sort_time(ls, i, j);
			else
				sort_ascii(ls, i, j);
			j++;
		}
		i++;
	}
	if (ls->r)
		sort_rec(ls);
	return (0);
}