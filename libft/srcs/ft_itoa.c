/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:14:27 by galemair          #+#    #+#             */
/*   Updated: 2018/04/04 12:48:51 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_intmin(void)
{
	char *str;

	if ((str = malloc(sizeof(char) * 12)) == NULL)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static int	ft_get_size(int n, int neg)
{
	int len;

	len = 0;
	if (neg == -1)
		len++;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_fill(int n, char *str, int len, int neg)
{
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (n > 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (neg == -1)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		neg;

	neg = 1;
	if (n == -2147483648)
		return (ft_intmin());
	if (n < 0)
	{
		neg = -1;
		n *= -1;
	}
	len = ft_get_size(n, neg);
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	return (ft_fill(n, str, len, neg));
}
