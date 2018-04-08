/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:24:34 by galemair          #+#    #+#             */
/*   Updated: 2018/04/08 19:02:43 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int i = 0;

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line1;
	int		ret;

	line = NULL;
	line1 = NULL;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
//	while (get_next_line(fd, &line) && get_next_line(fd2, &line1))
//	{
//		printf("FD1:%s\n", line);
//		printf("FD2:%s\n", line1);
//		free(line1);
//		line1 = NULL;
//		free(line);
//		line = NULL;
//		i++;
//	}
//	line = NULL;
//	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		i++;
	}
//	ret = get_next_line(fd, &line);
//	printf("ret = %d\n", ret);
//	free (line);
//	line = NULL;
//
//	ret = get_next_line(fd, &line);
//	printf("ret = %d\n", ret);
//	free (line);
//	line = NULL;
//
//	ret = get_next_line(fd, &line);
//	printf("ret = %d\n", ret);
//	free (line);
//	line = NULL;
//	get_next_line(fd, &line);
//	printf("FD1:%s\n", line);
//	free(line);
//	line = NULL;
//
//	printf("\n\n");
//
//	get_next_line(fd2, &line1);
//	printf("FD2:%s\n", line1);
//	free(line1);
//	line1 = NULL;
//
//
//	printf("\n\n");
//
//	get_next_line(fd, &line);
//	printf("FD1:%s\n", line);
//	free(line);
//	line = NULL;
//
//	printf("\n\n");
//
//	get_next_line(fd2, &line1);
//	printf("FD2:%s\n", line1);
//	free(line1);
//	line1 = NULL;
//
//	printf("\n\n");
//
//	get_next_line(fd, &line);
//	printf("FD1:%s\n", line);
//	free(line);
//	line = NULL;
//
//	printf("\n\n");
//
//	get_next_line(fd2, &line1);
//	printf("FD2:%s\n", line1);
//	free(line1);
//	line1 = NULL;
}
