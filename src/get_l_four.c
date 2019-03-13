/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_l_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <pcollio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:53:19 by pcollio-          #+#    #+#             */
/*   Updated: 2019/03/13 23:05:21 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_format(t_format *format)
{
	format->max0 = 0;
	format->max1 = 0;
	format->max2 = 0;
	format->max3 = 0;
	format->max4 = 0;
	format->max5 = 0;
}

void	sort_time_change(t_ls *ls, int i, int j)
{
	char *tmp;

	if (get_time_change((ls->files[i]), (ls->files[j]), ls) >= 0)
	{
		tmp = ls->files[i];
		ls->files[i] = ls->files[j];
		ls->files[j] = tmp;
	}
	if (get_time_change((ls->files[i]), (ls->files[j]), ls) == 0)
	{
		if (ft_strcmp((ls->files[i]), (ls->files[j])) > 0)
		{
			tmp = ls->files[i];
			ls->files[i] = ls->files[j];
			ls->files[j] = tmp;
		}
	}
}

void	l_format_print_dev_help(char *file, t_format *format)
{
	if (obj_type(file) == 2 || obj_type(file) == 3)
		ft_printf("%s %*d %-*s  %*d, %*d %s %s\n", format->chmod,
				format->max0, vtorya_hernya(file), format->max1, format->user,
				format->max3, get_major(file),
				format->max4, get_minor(file), format->date, format->name);
	else
		ft_printf("%s %*d %-*s  %*s %*lld %s %s\n", format->chmod,
				format->max0, vtorya_hernya(file), format->max1, format->user,
				format->max4, "     ", format->max5,
				get_size(file), format->date, format->name);
}

void	sort_time_change_objs(char **a, char **b, t_ls *ls)
{
	char	*tmp;

	if (get_time_change(*a, *b, ls) >= 0)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
	if (get_time_change(*a, *b, ls) == 0)
	{
		if (ft_strcmp(*a, *b) > 0)
		{
			tmp = *a;
			*a = *b;
			*b = tmp;
		}
	}
}
