/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 11:14:34 by drestles          #+#    #+#             */
/*   Updated: 2019/03/14 00:21:28 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	sort_time(t_ls *ls, int i, int j)
{
	char *tmp;

	if (get_time((ls->files[i]), (ls->files[j]), ls) >= 0)
	{
		tmp = ls->files[i];
		ls->files[i] = ls->files[j];
		ls->files[j] = tmp;
	}
	if (get_time((ls->files[i]), (ls->files[j]), ls) == 0)
	{
		if (ft_strcmp((ls->files[i]), (ls->files[j])) > 0)
		{
			tmp = ls->files[i];
			ls->files[i] = ls->files[j];
			ls->files[j] = tmp;
		}
	}
}

static void	sort_time_access(t_ls *ls, int i, int j)
{
	char *tmp;

	if (get_time_access((ls->files[i]), (ls->files[j]), ls) >= 0)
	{
		tmp = ls->files[i];
		ls->files[i] = ls->files[j];
		ls->files[j] = tmp;
	}
	if (get_time_access((ls->files[i]), (ls->files[j]), ls) == 0)
	{
		if (ft_strcmp((ls->files[i]), (ls->files[j])) > 0)
		{
			tmp = ls->files[i];
			ls->files[i] = ls->files[j];
			ls->files[j] = tmp;
		}
	}
}

static void	sort_ascii(t_ls *ls, int i, int j)
{
	char *tmp;

	if (ft_strcmp((ls->files[i]), (ls->files[j])) > 0)
	{
		tmp = ls->files[i];
		ls->files[i] = ls->files[j];
		ls->files[j] = tmp;
	}
}

static void	sort_rec(t_ls *ls)
{
	int		med;
	int		i;
	char	*tmp;

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

int			sort(t_ls *ls)
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
			else if (ls->u)
				sort_time_access(ls, i, j);
			else if (ls->c)
				sort_time_change(ls, i, j);
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
