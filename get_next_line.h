/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:40:50 by galemair          #+#    #+#             */
/*   Updated: 2018/04/11 15:11:50 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 100
# define ERROR -1
# define SUCCESS 1
# define EXIT_FINISH 0
# define NOT_FOUND -1

typedef struct s_perso	t_perso;

struct					s_perso
{
	char				*str;
	int					len;
	int					fd;
	int					eof;
	t_perso				*next;
};

int						get_next_line(const int fd, char **line);

#endif
