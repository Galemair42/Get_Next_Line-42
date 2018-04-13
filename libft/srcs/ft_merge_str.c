/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:15:44 by galemair          #+#    #+#             */
/*   Updated: 2018/04/04 12:47:35 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_merge_str(char *old, char *new)
{
	char *str;

	if ((str = malloc(sizeof(str) * (ft_strlen(old) +
		ft_strlen(new) + 1))) == NULL)
		return (NULL);
	ft_strcpy(str, old);
	ft_strcat(str, new);
	free(old);
	free(new);
	return (str);
}
