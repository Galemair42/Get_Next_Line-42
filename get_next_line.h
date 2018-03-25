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

# define BUF_SIZE 1
# define ERROR -1
# define SUCCESS 1
# define EXIT_FINISH 0
# define NOT_FOUND -1

typedef struct s_perso t_perso;

struct	s_perso
{
	char	*str;
	int	fd;
	int	eof;
	t_perso	*next;
};

int	get_next_line(const int fd, char **line);

#endif
