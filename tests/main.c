/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:24:34 by galemair          #+#    #+#             */
/*   Updated: 2018/04/06 15:40:45 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int i = 0;

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("Retour = %d\n", get_next_line(fd, &line));
		//printf("APPEL %d\n", i);
		printf("%s\n", line);
		free(line);
		line = NULL;
		i++;
	}
}
