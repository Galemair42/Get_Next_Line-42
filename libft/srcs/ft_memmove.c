/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:15:38 by galemair          #+#    #+#             */
/*   Updated: 2018/04/03 20:04:22 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;
	size_t	i;
	int		from;

	i = 0;
	c_src = (char *)src;
	c_dest = (char *)dest;
	from = 0;
	if (src < dest)
		from = n - 1;
	while (i < n)
	{
		if (from)
			c_dest[from - i] = c_src[from - i];
		else
			c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
