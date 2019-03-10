/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 11:08:25 by pcollio-          #+#    #+#             */
/*   Updated: 2019/03/10 11:12:01 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		**push_dir_files_to_str(char *path, char **obj, t_ls *ls)
{
	DIR				*d;
	int				count;
	struct dirent	*dir;
	int				i;
	int				j;
	int				n;
	char			*file;

	count = 0;
	d = opendir(path);
	i = 0;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
			if (dir->d_name[0] != '.' || ls->a)
			{
				file = dir->d_name;
				n = strlen(file);
				if (n > ls->max)
					ls->max = n;
				obj[i] = malloc(sizeof(char) * (n + 1));
				obj[i][n] = '\0';
				j = 0;
				while (j < n)
				{
					obj[i][j] = file[j];
					j++;
				}
				i++;
			}
		closedir(d);
	}
	return (obj);
}

void		push_dir_files(char *path, t_ls *ls)
{
	DIR				*d;
	int				count;
	struct dirent	*dir;

	count = 0;
	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
			if (dir->d_name[0] != '.')
				push_files(dir->d_name, ls);
		ls_files(ls);
		closedir(d);
	}
}

int			push_files(char *args, t_ls *ls)
{
	int		len;
	int		i;

	len = ft_strlen(args);
	if (len > ls->max)
		ls->max = len;
	ls->files[ls->index_f] = malloc(sizeof(char) * (len + 1));
	ls->files[ls->index_f][len] = '\0';
	i = 0;
	while (i < len)
	{
		ls->files[ls->index_f][i] = args[i];
		i++;
	}
	(ls->index_f)++;
	return (0);
}

int			push_dir(char *args, t_ls *ls)
{
	int	len;
	int	i;

	len = ft_strlen(args);
	ls->dir[ls->index_d] = malloc(sizeof(char) * (len + 1));
	ls->dir[ls->index_d][len] = '\0';
	i = 0;
	while (i < len)
	{
		ls->dir[ls->index_d][i] = args[i];
		i++;
	}
	(ls->index_d)++;
	return (0);
}