/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 10:01:40 by drestles          #+#    #+#             */
/*   Updated: 2019/03/10 13:44:11 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_rec(char *str, t_ls *ls)
{
	ls->max = 0;
	//здесь нужно фри
	ls->path = ft_strjoin(str, "/");
	if (ls->rec || ls->index_f)
		printf("\n%s:\n", str);
	else if (ls->index_d > 1 || ls->er)
		printf("%s:\n", str);
	int n = count_files(str, ls);
	char **objs;
	objs = malloc(sizeof(char*) * (n + 1));
	objs[n] = 0;
	objs = push_dir_files_to_str(str, objs, ls);
	objs = sort_objs(objs, n, ls);
	if (ls->l)
		l_format_rows_objs(objs, n, ls);
	else
		format_rows_objs(objs, n, ls);
	ls->rec++;
	if (ls->l_r)
	{
		ls->rec++;
		int i = 0;
		while (i < n)
		{
			char *a;
			a = ft_strjoin(str, "/");
			a = ft_strjoin(a, objs[i]);
			if (obj_type(a) == 1)
			{
				if (!(objs[i][0] == '.' && objs[i][1] == '\0')
					&& !(objs[i][0] == '.' && objs[i][1] == '.'))
					ls_rec(a, ls);
			}
			i++;
		}
	}
}

int parcer(t_ls *ls, int argc, char **argv)
{
	int i = 1;
	while (argc > 1 && flags(argv[i], ls) == 1)
	{
		argc--;
		i++;
	}
	int	c_f = 0;
	int	c_d = 0;
	int	j = i;
	int temp_argc = argc;
	while (temp_argc > 1)
	{
		if (is_exist(argv[j]) == 0)
		{
			printf("ls: %s: No such file or directory\n", argv[j]);
			ls->er = 1;
		}
		else if (obj_type(argv[j]) == 1)
			c_d++;
		else
			c_f++;
		j++;
		temp_argc--;
	}
	if (c_f > 0)
		malloc_files(c_f, ls);
	if (c_d > 0)
		malloc_dir(c_d, ls);
	if (c_f == 0 && c_d == 0 && ls->er == 0)
	{
		malloc_dir(1, ls);
		push_dir(".", ls);
		return (0);
	}
	while (argc > 1)
	{
		int z = obj_type(argv[i]);
		if (is_exist(argv[i]))
		{
			if (z == 1)
				push_dir(argv[i], ls);
			else
				push_files(argv[i], ls);
		}
		argc--;
		i++;
	}
	return (0);
}

int	ft_ls(t_ls *ls, int argc, char **argv)
{
	parcer(ls, argc, argv);
	ls_files(ls);
	char **a = dir_to_str(ls);
	int n = ft_strlen_two(a);
	a = sort_objs(a, n, ls);
	int i = 0;
	while(i < n)
	{
		ls_rec(a[i], ls);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_ls ls;
	init_struct(&ls);
	ft_ls(&ls, argc, argv);
	return (0);
}
