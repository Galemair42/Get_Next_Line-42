/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:15:44 by galemair          #+#    #+#             */
/*   Updated: 2018/04/10 18:22:54 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_merge(void *old1, void *old2, size_t old1_size, size_t old2_size)
{
	unsigned char	*new;
	size_t			i;

	i = 0;
	if (old1_size + old2_size <= 0)
		return (NULL);
	if ((new = ft_memalloc(old1_size + old2_size)) == NULL)
		return (NULL);
	ft_memcpy(new, old1, old1_size);
	while (i < old2_size)
	{
		new[i + old1_size] = ((unsigned char*)old2)[i];
		i++;
	}
	free(old1);
	old1 = NULL;
	return ((void*)new);
}
