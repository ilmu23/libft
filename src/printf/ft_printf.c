/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 05:31:01 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/30 08:45:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf_internal.h"

ssize_t	ft_printf(const char *f, ...)
{
	va_list	arg1;
	va_list	arg2;
	ssize_t	rval;
	size_t	size;
	char	*out;

	va_start(arg1, f);
	va_copy(arg2, arg1);;
	rval = ft_vsnprintf(NULL, 42, f, arg1);
	if (rval != -1)
	{
		size = (size_t)rval + 1;
		out = ft_calloc(size, sizeof(*out));
		rval = ft_vsnprintf(out, size, f, arg2);
	}
	va_end(arg1);
	va_end(arg2);
	if (rval == -1 || !out || write(1, out, (size_t)rval) == -1)
		return (-1);
	return (rval);
}
