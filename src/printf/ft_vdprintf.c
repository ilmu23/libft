/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:33:02 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 02:33:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf.h"

ssize_t	ft_vdprintf(int32_t fd, const char *f, va_list args)
{
	va_list	copy;
	ssize_t	rval;
	size_t	size;
	char	*out;

	va_copy(copy, args);
	rval = ft_vsnprintf(NULL, 42, f, copy);
	va_end(copy);
	if (rval != -1)
	{
		size = (size_t)rval + 1;
		out = ft_alloc(size);
		if (!out)
			return (-1);
		rval = ft_vsnprintf(out, size, f, args);
	}
	if (rval == -1 || write(fd, out, (size_t)rval) == -1)
		return (-1);
	return (rval);
}
