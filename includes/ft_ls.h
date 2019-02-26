/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:53:44 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/26 20:24:49 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H

# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <time.h>
# include "../libft/libft.h"
# include <grp.h>
# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>
# include <sys/ioctl.h>

typedef struct s_ls {
	int		l;
	int		r;
	int		l_r;
	int		a;
	int		t;

	char	**args;
	char	**files;
	char	**dir;
	int		index;
	int		max;
}				t_ls;

#endif
