/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <ckrommen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:59:59 by ckrommen          #+#    #+#             */
/*   Updated: 2017/09/29 13:55:05 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_memsize(char const *str, char c)
{
	int i;
	int count;
	int toggle;

	toggle = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			toggle = 0;
		else if (!toggle && str[i])
		{
			toggle = 1;
			count++;
		}
		i++;
	}
	return (count += 1);
}

static	int		ft_strsubcount(char const *s, int index, char c)
{
	int i;

	i = 0;
	while (s[index] != c && s[index])
	{
		index++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		y;
	int		x;
	int		i;
	char	**new;

	x = 0;
	i = 0;
	new = s ? (char **)malloc((ft_memsize(s, c)) * sizeof(char *)) : NULL;
	if (!new || !ft_memsize(s, c))
		return (NULL);
	while (s[i])
	{
		y = 0;
		while (s[i] == c && s[i])
			i++;
		if (ft_strsubcount(s, i, c) != 0)
		{
			new[x] = ft_strnew(ft_strsubcount(s, i, c));
			while (s[i] != c && s[i])
				new[x][y++] = s[i++];
			new[x++][y] = '\0';
		}
	}
	new[x] = 0;
	return (new);
}
