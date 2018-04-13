/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:19:41 by galemair          #+#    #+#             */
/*   Updated: 2018/04/03 20:20:42 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = (char *)haystack;
	if (!haystack[i] && !needle[i])
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == needle[j] && needle[j])
			j++;
		if (needle[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}
