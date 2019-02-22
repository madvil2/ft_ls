/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:49:07 by drestles          #+#    #+#             */
/*   Updated: 2019/02/14 18:14:23 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size + 1 < size)
		return (NULL);
	if (!(str = (char *)(malloc(sizeof(char) * (size + 1)))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
