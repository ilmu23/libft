/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:41:02 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/08 13:59:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	slen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(&s[start]);
	if (len > slen)
		len = slen;
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, &s[start], len + 1);
	return (out);
}
