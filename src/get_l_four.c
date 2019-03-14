/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_l_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:53:19 by pcollio-          #+#    #+#             */
/*   Updated: 2019/03/14 20:57:13 by pcollio-         ###   ########.fr       */
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
