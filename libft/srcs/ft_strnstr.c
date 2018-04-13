/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:19:12 by galemair          #+#    #+#             */
/*   Updated: 2018/04/03 20:10:49 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*str;
	size_t		i;
	int			j;

	i = 0;
	str = (char *)haystack;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == needle[j] && (i + j) < len && needle[j])
			j++;
		if (needle[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}
