/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:15:27 by galemair          #+#    #+#             */
/*   Updated: 2018/04/03 19:58:48 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*srcs;
	char		*dests;

	dests = dst;
	srcs = src;
	while (n > 0)
	{
		*dests = *srcs;
		n--;
		dests++;
		srcs++;
	}
	return (dst);
}
