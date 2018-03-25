#include "get_next_line.h"

int	ft_read(const int fd, t_perso *tab)
{
	char	*buf;
	int	ret;

	if ((buf = malloc(sizeof(buf) * (BUF_SIZE + 1))) == NULL)
		return (ERROR);
	if ((ret = read(fd, buf, BUF_SIZE)) == ERROR)
		return (ERROR);
	buf[BUF_SIZE] = '\0';
	if (tab->str)
		tab->str = ft_merge_str(tab->str, buf);
	else
	{
		tab->str = ft_strnew(BUF_SIZE + 1);
		tab->str = ft_strcpy(tab->str, buf);
		free(buf);
		buf = NULL;
	}
	if (ret < BUF_SIZE)
		tab->eof = 1;
	return (EXIT_FINISH);
}

int	ft_line_is_full(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NOT_FOUND);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (NOT_FOUND);
}
int	ft_fill_line(const int fd, t_perso *tmp, char **line)
{
	int line_length;

	while ((ft_line_is_full(tmp->str)) == NOT_FOUND && tmp->eof == 0)
		ft_read(fd, tmp);
	line_length = ft_line_is_full(tmp->str);
	if (line_length == NOT_FOUND)
	{
		*line = malloc(sizeof(char) * (ft_strlen(tmp->str) + 1));
		*line = ft_strcpy(*line, tmp->str);
		free(tmp->str);
		return (EXIT_FINISH);
	}
	if((*line = malloc(sizeof(char) * (line_length + 1))) == NULL)
	return (ERROR);
	*line = ft_strncpy(*line, tmp->str, line_length);
	(*line)[line_length] = '\0';
	tmp->str = ft_reduce_str(tmp->str, line_length + 1);
	if ((tmp->str) == NULL && tmp->eof == 1)
		return (EXIT_FINISH);
	return (SUCCESS);
}

int	get_next_line(const int fd, char **line)
{
	static t_perso	*tab;
	t_perso		*tmp;
	
	if (!tab)
	{
		if ((tab = malloc(sizeof(t_perso))) == NULL)
			return (ERROR);
		tab->fd = fd;
		tab->str = NULL;
		tab->next = NULL;
		tab->eof = 0;
	}	
	tmp = tab;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		if ((tmp = malloc(sizeof(t_perso))) == NULL)
			return (ERROR);
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->next = NULL;
		tmp->eof = 0;
	}	
	return (ft_fill_line(fd, tmp, line));
}

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int i = 0;
	
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("APPEL %d\n", i);
		printf("%s\n\n", line);
		line = NULL;
		free(line);
		i++;
	}
	return (0);
}
