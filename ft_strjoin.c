/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:51:41 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 10:00:11 by ivalimak         ###   ########.fr       */
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
	ft_push(ft_getvm(), 2, s1, s2);
	out = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!out)
		return (NULL);
	if (s1)
		ft_strlcpy(out, s1, len1 + 1);
	ft_strlcpy((out + len1), s2, len2 + 1);
	ft_popn(ft_getvm(), 1 + (s1 != NULL));
	return (out);
}
