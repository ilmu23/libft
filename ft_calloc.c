/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:46 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 14:01:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;
	size_t	asize;

	asize = count * size;
	if (asize < count && asize < size)
		return (NULL);
	out = ft_alloc(count * size);
	if (!out)
		return (NULL);
	ft_bzero(out, count * size);
	return (out);
}
