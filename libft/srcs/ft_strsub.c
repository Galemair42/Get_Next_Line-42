/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:19:49 by galemair          #+#    #+#             */
/*   Updated: 2018/04/04 14:01:19 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			l;

	if (!s)
		return (NULL);
	l = 0;
	i = start;
	if ((str = malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	while (l < len)
	{
		str[l] = s[i];
		i++;
		l++;
	}
	str[l] = '\0';
	return (str);
}
