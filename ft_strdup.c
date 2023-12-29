/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:56:01 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 20:23:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	asize;

	asize = ft_strlen(s1) + 1;
	ft_push((void *)s1);
	out = ft_calloc(asize, sizeof(char));
	ft_pop();
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, asize);
	return (out);
}
