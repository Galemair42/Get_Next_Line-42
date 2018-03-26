#include "get_next_line.h"

int i = 0;
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
	{
		if (ft_read(fd, tmp) == ERROR)
			return (ERROR);
	}
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

void	print_list(t_perso *tab)
{
	while (tab)
	{
		printf("fd = %d\n", tab->fd);
		printf("eof = %d\n", tab->eof);
		printf("str = %s\n", tab->str);
		tab = tab->next;
	}
}
t_perso	*init_struct(t_perso *tab, const int fd)
{
	tab->fd = fd;
	tab->str = NULL;
	tab->next = NULL;
	tab->eof = 0;
	return (tab);
}
int	get_next_line(const int fd, char **line)
{
	static t_perso	*tab;
	t_perso		*tmp;
	t_perso		*tmp2;	

	if (!tab)
	{
		if ((tab = malloc(sizeof(t_perso))) == NULL)
			return (ERROR);
		tab = init_struct(tab, fd);
	}	
	tmp = tab;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp2 = tab;
		while (tmp2->next)
			tmp2 = tmp2->next;
		if ((tmp = malloc(sizeof(t_perso))) == NULL)
			return (ERROR);
		tmp2->next = tmp;
		tmp = init_struct(tab, fd);
	}
	//print_list(tmp);
	return (ft_fill_line(fd, tmp, line));
}

int	main(int argc, char **argv)
{
	int fd;
	int fd2;
	char *line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
//	while (get_next_line(fd, &line))
//	{
//		printf("APPEL %d\n", i);
//		printf("%s\n\n", line);
//		free(line);
//		line = NULL;
//		i++;
//	}
//	printf("APPEL %d\n", i);
//	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("fd 1 =%s\n", line);
	free(line);
	line = NULL;
	get_next_line(fd2, &line);
	printf("fd 2 =%s\n", line);
	free(line);
	line = NULL;
	get_next_line(fd, &line);
	printf("fd 1 =%s\n", line);
	free(line);
	line = NULL;	
	get_next_line(fd2, &line);
	printf("fd 2 =%s\n", line);
	free(line);
	line = NULL;
	return (0);
}
