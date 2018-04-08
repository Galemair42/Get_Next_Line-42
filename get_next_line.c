/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:29:21 by galemair          #+#    #+#             */
/*   Updated: 2018/04/08 18:56:31 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read(const int fd, t_perso *tab)
{
	char	buff[BUFF_SIZE];
	int		ret;
	char	*tmp;

	if ((ret = read(fd, buff, BUFF_SIZE)) == ERROR)
		return (ERROR);
	if (tab->len == 0)
	{
		if ((tab->str = malloc(sizeof(char) * ret)) == NULL)
			return (ERROR);
		ft_memcpy(tab->str, buff, ret);
		tab->len = ret;
	}
	else
	{
		tmp = ft_merge(tab->str, buff, tab->len, ret);
		free(tab->str);
		tab->str = tmp;
		tab->len += ret;
	}
	if (ret < BUFF_SIZE)
		tab->eof = 1;
	return (SUCCESS);
}

int		ft_line_is_full(t_perso *tab)
{
	int		i;
	char	*str;

	str = tab->str;
	i = 0;
	while (i < tab->len)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (NOT_FOUND);
}

int		ft_fill_line(const int fd, t_perso *tab, char **line)
{
	int line_length;

	while (ft_line_is_full(tab) == NOT_FOUND && tab->eof == 0)
		if ((ft_read(fd, tab)) == ERROR)
			return (ERROR);
	if (tab->eof == 1 && tab->len == 0)
		return (EXIT_FINISH);
	line_length = ft_line_is_full(tab);
	if (line_length == NOT_FOUND && tab->eof == 1)
	{
		if ((*line = ft_strnew(tab->len)) == NULL)
			return (ERROR);
		ft_memcpy(*line, tab->str, tab->len);
		tab->len = 0;
		free(tab->str);
		tab->str = NULL;
		return (SUCCESS);
	}
	if ((*line = ft_strnew(line_length)) == NULL)
		return (ERROR);
	ft_memcpy(*line, tab->str, line_length);
	tab->str = (char *)ft_reduce(tab->str, line_length + 1, tab->len);
	tab->len -= (line_length + 1);
	return (SUCCESS);
}

t_perso	*init_struct(t_perso *tab, const int fd)
{
	tab->fd = fd;
	tab->str = NULL;
	tab->next = NULL;
	tab->len = 0;
	tab->eof = 0;
	return (tab);
}

int		get_next_line(const int fd, char **line)
{
	static t_perso	*tab = NULL;
	t_perso			*tmp;
	t_perso			*tmp2;

	if (!line)
		return (ERROR);
	*line = NULL;
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
		tmp = init_struct(tmp, fd);
	}
	return (ft_fill_line(fd, tmp, line));
}
