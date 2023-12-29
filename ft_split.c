/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:02:23 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 12:05:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getsplits(char const *s, char c);
static char		*makesplit(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	splits;
	size_t	i;

	if (!s)
		return (NULL);
	splits = getsplits(s, c);
	ft_push(ft_getvm(), 1, s);
	out = ft_calloc((splits + 1), sizeof(char *));
	ft_pop(ft_getvm());
	ft_push(ft_getvm(), 1, out);
	if (!out)
		return (NULL);
	i = 0;
	while (i <= splits)
	{
		out[i] = makesplit(s, c);
		if (!out[i] && i <= splits)
			return (NULL);
		if (out[i++])
			ft_push(ft_getvm(), 1, out[i - 1]);
	}
	return (out);
}

static size_t	getsplits(char const *s, char c)
{
	size_t	i;
	size_t	splits;

	if (!c)
	{
		if (!*s)
			return (0);
		return (1);
	}
	i = 0;
	splits = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			splits++;
	}
	return (splits);
}

static char	*makesplit(char const *s, char c)
{
	static size_t	i = 0;
	size_t			j;
	char			*out;

	while (s[i] && s[i] == c)
		i++;
	j = i;
	while (s[i] && s[i] != c)
		i++;
	if (j == i)
	{
		i = 0;
		return (NULL);
	}
	out = ft_substr(s, j, i - j);
	if (!out)
		return (NULL);
	return (out);
}
