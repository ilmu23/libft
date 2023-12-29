/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:01:45 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 20:24:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsjoin(char const *s1, char const *s2, char sep)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*out;

	i = 1;
	if (!s2)
		return (NULL);
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	len2 = ft_strlen(s2);
	if (sep)
		i++;
	ft_pushn(2, s1, s2);
	out = ft_calloc(len1 + len2 + i, sizeof(char));
	if (s1)
		ft_strlcpy(out, s1, len1 + 1);
	if (sep)
		out[len1] = sep;
	ft_strlcpy(&out[ft_strlen(out)], s2, len2 + 1);
	ft_popn(1 + (s1 != NULL));
	return (out);
}
