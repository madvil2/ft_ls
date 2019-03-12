/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:44:10 by drestles          #+#    #+#             */
/*   Updated: 2019/03/13 00:41:14 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*lists;

	lists = lst;
	while (!lists || !f)
		return ;
	while (lists->next)
	{
		f(lists);
		lists = lists->next;
	}
	f(lists);
}
