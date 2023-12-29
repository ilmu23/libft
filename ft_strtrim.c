/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:00:57 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 20:25:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	ft_push((void *)s1);
	if (!(*s1))
		return (ft_strdup(""));
	ft_pop();
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_contains(set, s1[i]) == 1)
		i++;
	while (ft_contains(set, s1[j]) == 1 && j > i)
		j--;
	return (ft_substr(s1, i, j + 1 - i));
}
