/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:19:33 by galemair          #+#    #+#             */
/*   Updated: 2018/04/04 13:39:13 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_tab(char const *s, char c, char ***tab)
{
	char	**tmp;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i + 1] == c || s[i + 1] == '\0')
		{
			count++;
			while (s[i + 1] == c && s[i])
				i++;
		}
		i++;
	}
	if ((tmp = malloc(sizeof(char*) * (count + 1))) == NULL)
		return (-1);
	*tab = tmp;
	return (count);
}

static char	*ft_fill_str(char const *s, size_t i, size_t size)
{
	char	*str;
	size_t	j;

	j = 0;
	if ((str = ft_strnew((size))) == NULL)
		return (NULL);
	while (j < size)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	return (str);
}

static char	**fill_tab(char **tab, size_t split, char const *s, char c)
{
	size_t		j;
	size_t		i;
	size_t		words;

	words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (words < split && s[i])
	{
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		tab[words] = ft_fill_str(s, i, j);
		i += j;
		words++;
		while (s[i] && s[i] == c)
			i++;
	}
	tab[words] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	split;

	if (!s)
		return (NULL);
	tab = NULL;
	if ((split = ft_get_tab(s, c, &tab)) == -1)
		return (NULL);
	return (fill_tab(tab, split, s, c));
}
