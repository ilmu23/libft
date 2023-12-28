/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:56:22 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 14:21:11 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strremove(const char *s, const char c)
{
	size_t	i;
	char	**arr;
	char	*tmp;
	char	*out;

	arr = ft_split(s, c);
	if (!arr)
		return (NULL);
	i = 0;
	out = NULL;
	while (arr[i])
	{
		tmp = ft_strjoin(out, arr[i]);
		out = tmp;
	}
	return (out);
}
