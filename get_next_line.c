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
		tab->str = buf;
	if (ret == BUF_SIZE)
		return (SUCCESS);
	return (EXIT_FINISH);
}

int	ft_line_is_full(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;

	}
	return (-1);
}
int	ft_fill_line(const int fd, t_perso *tmp, char **line)
{
	int line_length;

	while ((line_length = ft_line_is_full(tmp->str)) == -1)
		ft_read(fd, tmp);
	if((*line = malloc(sizeof(char) * (line_length + 1))) == NULL)
		return (ERROR);
	ft_strncpy(*line, tmp->str, line_length);
	return (1);
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
	}	
	return (ft_fill_line(fd, tmp, line));
}

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;

	i = 1;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}
