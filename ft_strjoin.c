/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:51:41 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 22:08:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*out;

	if (!s2)
		return (NULL);
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	len2 = ft_strlen(s2);
	if (s1)
		ft_push(ft_getvm(), (void *)s1);
	ft_push(ft_getvm(), (void *)s2);
	out = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!out)
		return (NULL);
	if (s1)
		ft_strlcpy(out, s1, len1 + 1);
	ft_strlcpy((out + len1), s2, len2 + 1);
	ft_pop(ft_getvm());
	if (s1)
		ft_pop(ft_getvm());
	return (out);
}
