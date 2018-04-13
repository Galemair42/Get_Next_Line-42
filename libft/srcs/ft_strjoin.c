/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:18:02 by galemair          #+#    #+#             */
/*   Updated: 2018/04/04 14:01:42 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (NULL);
	if ((str = malloc(sizeof(str) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
