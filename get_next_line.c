/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:29:21 by galemair          #+#    #+#             */
/*   Updated: 2018/04/12 14:18:48 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read(const int fd, t_perso *tab)
{
	char	buff[BUFF_SIZE];
	int		ret;

	if ((ret = read(fd, buff, BUFF_SIZE)) == ERROR)
		return (ERROR);
	if (tab->len == 0 && ret != 0)
	{
		if ((tab->str = malloc(sizeof(char) * ret)) == NULL)
			return (ERROR);
		ft_memcpy(tab->str, buff, ret);
		tab->len = ret;
	}
	else if (ret != 0)
	{
		tab->str = ft_merge(tab->str, buff, tab->len, ret);
		tab->len += ret;
	}
	if (ret == 0)
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

int		ft_clean_list(const int fd, t_perso **list)
{
	t_perso *tmp1;
	t_perso *tmp2;

	tmp1 = *list;
	if ((*list)->fd == fd)
	{
		tmp1 = (*list)->next;
		free(*list);
		*list = tmp1;
		return (EXIT_FINISH);
	}
	while ((tmp1->next)->fd != fd)
		tmp1 = tmp1->next;
	tmp2 = (tmp1->next)->next;
	free(tmp1->next);
	tmp1->next = tmp2;
	return (EXIT_FINISH);
}

int		ft_fill_line(const int fd, t_perso *tab, char **line, t_perso **list)
{
	int line_length;

	*line = NULL;
	while (ft_line_is_full(tab) == NOT_FOUND && tab->eof == 0)
		if ((ft_read(fd, tab)) == ERROR)
			return (ERROR);
	if (tab->eof == 1 && tab->len == 0)
		return (ft_clean_list(fd, list));
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

int		get_next_line(const int fd, char **line)
{
	static t_perso	*tab = NULL;
	t_manip		tmp;

	if (!line)
		return (ERROR);
	if (!tab)
	{
		if ((tab = ft_memalloc(sizeof(t_perso))) == NULL)
			return (ERROR);
		tab->fd = fd;
	}
	tmp.p = tab;
	while (tmp.p && (tmp.p)->fd != fd)
		tmp.p = (tmp.p)->next;
	if (!(tmp.p))
	{
		tmp.t = tab;
		while ((tmp.t)->next)
			tmp.t = (tmp.t)->next;
		if ((tmp.p = ft_memalloc(sizeof(t_perso))) == NULL)
			return (ERROR);
		(tmp.p)->fd = fd;
		(tmp.t)->next = tmp.p;
	}
	return (ft_fill_line(fd, tmp.p, line, &tab));
}
