/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:19:08 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/04 20:44:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 */

#include "libft.h"

/** Copies n bytes from src to dst
 *
 * Ensures the data from src gets copied
 * to dst, even if they overlap
 * @param *dst Pointer to copy to
 * @param *src Pointer to copy from
 * @param n Amount of bytes to copy
 * @retval void * Pointer to the destination
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst || !src)
		return (dst);
	if (dst > src)
		ft_memcpy(dst, src, len);
	else
	{
		i = 0;
		while (i < len - 8)
		{
			*(uint64_t *)(dst + i) = *(uint64_t *)(src + i);
			i += 8;
		}
		while (i < len)
		{
			*(uint8_t *)(dst + i) = *(uint8_t *)(src + i);
			i++;
		}
	}
	return (dst);
}
