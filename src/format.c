/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 10:01:49 by drestles          #+#    #+#             */
/*   Updated: 2019/03/10 10:53:56 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

int	l_format_rows(t_ls *ls)
{
	int i = 0;
	char *chmod;
	char *user;
	char *group;
	char *date;
	char *name;
	int max0 = 0;
	int	max1 = 0;
	int	max2 = 0;
	int max3 = 0;
	int	max4 = 0;
	int	max5 = 0;
	while (i < ls->index_f)
	{
		int max;

		max = ft_intlen(vtorya_hernya(ls->files[i]));
		if (max > max0)
			max0 = max;
		max = ft_strlen(get_user(ls->files[i]));
		if (max > max1)
			max1 = max;
		max = ft_strlen(get_group(ls->files[i]));
		if (max > max2)
			max2 = max;
		max = ft_intlen(get_major(ls->files[i]));
		if (max > max3)
			max3 = max;
		max = ft_intlen(get_minor(ls->files[i]));
		if (max > max4)
			max4 = max;
		max = ft_intlen(get_size(ls->files[i]));
		if (max > max5)
			max5 = max;
		i++;
	}
	i = 0;
	while (i < ls->index_f)
	{
		//здесь нужно фришнуть
		chmod = get_chmod(ls->files[i]);
		user = get_user(ls->files[i]);
		group = get_group(ls->files[i]);
		date = get_last_time(ls->files[i]);
		name = put_link(ls->files[i]);
		printf("%s %*d %*s %*s %*lld %s %s\n", chmod, max0, vtorya_hernya(ls->files[i]),
			max1, user, max2, group, max5, get_size(ls->files[i]), date, name);
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

int	l_format_rows_objs(char **objs, int n, t_ls *ls)
{
	int total;
	total = get_total_size(objs, ls);
	printf ("total %d\n", total);
	int i = 0;
	char *file;
	char *chmod;
	char *user;
	char *group;
	char *date;
	char *name;
	int max0 = 0;
	int	max1 = 0;
	int	max2 = 0;
	int max3 = 0;
	int	max4 = 0;
	int	max5 = 0;
	while (i < n)
	{
		//здесь нужно фришнуть
		file = ft_strjoin(ls->path, objs[i]);
		int max;
		max = ft_intlen(vtorya_hernya(file));
		if (max > max0)
			max0 = max;
		max = ft_strlen(get_user(file));
		if (max > max1)
			max1 = max;
		max = ft_strlen(get_group(file));
		if (max > max2)
			max2 = max;
		max = ft_intlen(get_major(file));
		if (max > max3)
			max3 = max;
		max = ft_intlen(get_minor(file));
		if (max > max4)
			max4 = max;
		max = ft_intlen(get_size(file));
		if (max > max5)
			max5 = max;
		i++;
	}
	i = 0;
	if (ft_strstr(ls->path, "/dev"))
	{
		while (i < n)
		{
			//здесь нужно фришнуть
			file = ft_strjoin(ls->path, objs[i]);
			chmod = get_chmod(file);
			user = get_user(file);
			group = get_group(file);
			date = get_last_time(file);
			name = put_link(file);
			printf("%s %*d %-*s  %-*s  %*d, %*d %s %s\n", chmod, max0, vtorya_hernya(file),
				max1, user, max2, group, max3, get_major(file), max4, get_minor(file),
				date, name);
			i++;
		}
		return (0);
	}
	while (i < n)
	{
		//здесь нужно фришнуть
		file = ft_strjoin(ls->path, objs[i]);
		chmod = get_chmod(file);
		user = get_user(file);
		group = get_group(file);
		date = get_last_time(file);
		name = put_link(file);
		printf("%s %*d %-*s  %-*s  %*lld %s %s\n", chmod, max0, vtorya_hernya(file),
			max1, user, max2, group, max5, get_size(file), date, name);
		i++;
	}
	return (0);
}
